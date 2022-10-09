#include <iostream>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long q = n / k;

	if (q % 2 == 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}