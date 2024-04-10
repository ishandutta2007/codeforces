// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, q;
string s;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> q >> s;
		while (q--) {
			int l, r;
			cin >> l >> r;
			l--;
			if (s.substr(0, l).find(s[l]) != string::npos || s.substr(r).find(s[r-1]) != string::npos) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}