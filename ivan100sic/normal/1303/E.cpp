#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s, p;
		cin >> s >> p;
		int m = p.size(), ok = 0;
		for (int k=0; k<=m; k++) {
			int l = m - k;
			string a = p.substr(0, k);
			string b = p.substr(k);

			vector<int> ol(k+1, -1);
			ol[0] = 0;

			for (char c : s) {
				auto nu = ol;
				for (int i=0; i<=k; i++) {
					int j = ol[i];
					if (j == -1)
						continue;
					if (i < k && c == a[i])
						nu[i+1] = max(nu[i+1], ol[i]);
					if (j < l && c == b[j])
						nu[i] = max(nu[i], ol[i]+1);
				}
				swap(ol, nu);
			}

			if (ol[k] == l) {
				ok = 1;
				break;
			}
		}

		cout << (ok ? "YES\n" : "NO\n");
	}
}