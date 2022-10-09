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
		int n, m, z=0;
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			if (i < n-1) {
				if (s.back() != 'D') {
					z++;
				}
			} else {
				for (int j=0; j<m-1; j++) {
					if (s[j] != 'R') {
						z++;
					}
				}
			}
		}
		cout << z << '\n';
	}
}