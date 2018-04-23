#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include<algorithm>

class Minge {

private:
	//std::string firma;
	std::string getFirma() {
		return firma;
	};

public:
	std::string firma;
	Minge();
	Minge(std::string firma) : firma(firma) {}
	~Minge() {}
	Minge(const Minge& old) {
		this->firma = old.firma;
	}
	Minge& operator =(Minge& old) {
		this->firma = old.firma;
		return *this;
	}
	Minge(Minge&& old) {
		this->firma = old.firma;
	}
	Minge& operator=(Minge&& old) {
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, Minge& a) {
		os << a.firma << " ";
		return os;
	}
	friend bool operator==(Minge& x, Minge& k) {
		if (x.firma.compare(k.firma) == 0) return true;
		else return false;
	}

};



int main() {
	Minge m1("Puma");
	Minge m3("Nike");
	Minge m2 = Minge(m3);
	m2 = m1;
	std::cout << std::endl;


	std::vector<Minge> vectorMinge;

	vectorMinge.push_back(m1);
	vectorMinge.push_back(m2);
	vectorMinge.push_back(m3);
	Minge m4("Adidas");
	//vectorMinge.insert(vectorMinge.begin() + 1, m4);
	vectorMinge.push_back(m4);

	std::cout << "Vectorul de mingi este: ";
	for (auto i = 0; i < vectorMinge.size(); i++) {
		std::cout << vectorMinge[i] << " | ";
	}

	std::vector<Minge>::iterator it = std::find_if(vectorMinge.begin(), vectorMinge.end(), [](Minge& m) {
		if (m.firma.compare("Adidas") == 0) return true;
		else return false;
	});

	std::cout << std::endl;
	std::cout << "Exista minge Adidas? " << std::endl;
	std::cout << *it << std::endl;
	std::cout << "Stergere minge" << std::endl;


	vectorMinge.erase(std::remove_if(vectorMinge.begin(), vectorMinge.end(), [](Minge& m) {
		if (m.firma.compare("Adidas") == 0) return true;
		else return false;
	}), vectorMinge.end());

	std::cout << "Vectorul nou de mingi este: ";
	for (auto i = 0; i < vectorMinge.size(); i++) {
		std::cout << vectorMinge[i] << " | ";
	}

	std::cout << std::endl;
	system("pause");
}