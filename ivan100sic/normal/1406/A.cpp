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
		int n, z=0;
		cin >> n;
		vector<int> c(111);
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			c[x]++;
		}

		for (int x=0; x<111; x++) {
			int ok = 1;
			for (int i=0; i<x; i++) {
				c[i]--;
				if (c[i] < 0) ok = 0;
			}

			if (ok) {
				int j = x;
				for (int i=0; i<111; i++) {
					if (c[i] == 0) {
						j += i;
						break;
					}
				}

				z = max(z, j);
			}

			for (int i=0; i<x; i++) {
				c[i]++;
			}
		}

		cout << z << '\n';
	}
}