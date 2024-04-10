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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		bool ok = 1;
		for (int r=0; r<k; r++) {
			set<char> t;
			for (int i=r; i<n; i+=k) t.insert(s[i]);
			if (t.count('0') && t.count('1')) {
				ok = 0;
			} else if (t.size()) {
				for (int i=r; i<n; i+=k) {
					s[i] = *t.begin();
				}
			}
		}

		int f[2] = {0, 0};
		for (int i=0; i<k; i++) {
			if (isdigit(s[i])) {
				f[s[i]-'0']++;
			}
		}
		if (max(f[0], f[1]) > k/2) {
			ok = 0;
		}

		cout << (ok ? "YES\n" : "NO\n");
	}
}