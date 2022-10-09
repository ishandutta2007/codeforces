#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int a[105];

int main() {
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}

	if (count(a, a + n, 0) == n) {
		cout << "YES\n";
		return 0;
	}

	for (int sum = 1; sum <= 999; sum++) {
		int z = 0, ok = 1, cnt = 0;
		for (int i = 0; i < n; i++) {
			z += a[i];
			if (z == sum) {
				z = 0;
				cnt++;
			}
			else if (z > sum) {
				ok = 0;
			}
		}
		if (z)
			ok = 0;
		if (cnt < 2)
			ok = 0;
		if (ok) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}