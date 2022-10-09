#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int q[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<27; i++) {
		int x = (1 << i) - 1;
		q[i] = 1;
		for (int d=2; d*d <= x; d++) {
			if (x % d == 0) {
				q[i] = x / d;
				break;
			}
		}
	}

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		int c = 32 - __builtin_clz(x);
		if (x == (1 << c) - 1) {
			cout << q[c] << '\n';
		} else {
			cout << (1 << c) - 1 << '\n';
		}
	}
}