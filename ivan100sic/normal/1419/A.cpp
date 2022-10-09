// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		if (n % 2 == 0) {
			// drugi igrac ima zadnji potez, moze li da napravi parno?
			int f = 0;
			for (int i=1; i<n; i+=2) {
				if (s[i] % 2 == 0) {
					f = 1;
				}
			}

			cout << (f ? 2 : 1) << '\n';
		} else {
			int f = 0;
			for (int i=0; i<n; i+=2) {
				if (s[i] % 2 == 1) {
					f = 1;
				}
			}

			cout << (f ? 1 : 2) << '\n';
		}
	}
}