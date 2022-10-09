#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	int c[3] = {0, 0, 0};
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}
	if (c[1] && c[2]) {
		cout << "2 1 ";
		c[1]--;
		c[2]--;
		while (c[1] >= 2) {
			c[1] -= 2;
			cout << "1 1 ";
		}
		while (c[2] >= 1) {
			c[2] -= 1;
			cout << "2 ";
		}
		if (c[1])
			cout << "1 ";
	} else {
		while (c[1] >= 1) {
			c[1] -= 1;
			cout << "1 ";
		}
		while (c[2] >= 1) {
			c[2] -= 1;
			cout << "2 ";
		}
	}
}