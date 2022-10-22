#include <iostream>

using namespace std;

string name[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main() {
	int n;
	cin >> n;
	n--;
	int m = 1;
	while (5*m <= n) {
		n -= 5*m;
		m *= 2;
	}
	cout << name[n/m] << endl;
	return 0;
}