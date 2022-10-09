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
		int n, ok = 0;
		cin >> n;
		for (int i=0; i<335; i++) {
			for (int j=0; j<202; j++) {
				int z = n-3*i-5*j;
				if (z >= 0 && z % 7 == 0) {
					cout << i << ' ' << j << ' ' << z/7 << '\n';
					ok = 1;
					i = j = 123123;
					break;
				}
			}
		}
		if (!ok) {
			cout << "-1\n";
		}
	}
}