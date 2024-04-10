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
		string s;
		cin >> s;
		int n = s.size();
		vector<int> z(n+1);
		for (int i=0; i<n; i++) {
			z[i+1] = z[i] + (s[i] == '-' ? -1 : 1);
		}
		vector<int> foc(n+2, -1);
		for (int i=n; i>=1; i--) {
			if (z[i] < 0) {
				foc[-z[i]] = i;
			}
		}
		ll res = 0;
		for (int i=1; i<=n+1; i++) {
			if (foc[i] == -1) {
				res += n;
				break;
			} else {
				res += foc[i];
			}
		}
		cout << res << '\n';
	}
}