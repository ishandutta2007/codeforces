#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;

	cin >> n;

	if (n % 2) {
		cout << n / 2 << '\n';
		cout << 3;
		for (int i=0; i<n/2-1; i++) {
			cout << ' ' << 2;
		}
	} else {
		cout << n / 2 << '\n';
		for (int i=0; i<n/2; i++) {
			cout << ' ' << 2;
		}
	}

}