// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	int n, p, q;
	cin >> n >> p >> q;
	cin >> s;
	for (int x=0; x<=n; x++) {
		for (int y=0; y<=n; y++) {
			if (p*x + q*y == n) {
				cout << x + y << '\n';

				int b = 0;

				for (int i=0; i<x; i++) {
					cout << s.substr(b, p) << '\n';
					b += p;
				}

				for (int i=0; i<y; i++) {
					cout << s.substr(b, q) << '\n';
					b += q;
				}

				cout << '\n';
				return 0;
			}
		}
	}

	cout << "-1\n";
}