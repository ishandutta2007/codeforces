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

	long long n;
	cin >> n;

	if (n % 2 == 0) {
		cout << n/2;
	} else {
		cout << n/2 - n;
	}
}