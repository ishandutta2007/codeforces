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
		string s[10];
		int n, m;
		cin >> n >> m;
		for (int i=0; i<n; i++)
			cin >> s[i];

		auto dif = [&](string a, string b) {
			int z = 0;
			for (int i=0; i<m; i++) {
				z += a[i] != b[i];
			}
			return z;
		};

		auto moze = [&](string t) {
			for (int i=0; i<n; i++) {
				if (dif(t, s[i]) > 1)
					return false;
			}
			return true;
		};

		string q = "-1";

		for (int i=0; i<m; i++) {
			for (char j='a'; j<='z'; j++) {
				string u = s[0];
				u[i] = j;
				if (moze(u)) {
					q = u;
				}
			}
		}

		cout << q << '\n';

	}
}