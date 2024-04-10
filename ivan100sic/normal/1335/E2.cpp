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
		vector<int> a(n);
		vector<basic_string<int>> e(200);
		vector<vector<int>> c(n+1, vector<int>(200));
		for (int i=0; i<n; i++) {
			cin >> a[i];
			a[i]--;
			e[a[i]] += i;
			c[i+1][a[i]]++;
		}

		for (int j=1; j<=n; j++)
			for (int i=0; i<200; i++)
				c[j][i] += c[j-1][i];

		auto daj = [&](int l, int r) {
			int h = 0;
			for (int i=0; i<200; i++) {
				h = max(h, c[r][i] - c[l][i]);
			}
			return h;
		};

		int u = 0;

		for (int i=0; i<200; i++) {
			int w = e[i].size() / 2;
			for (int j=0; j<w; j++) {
				int l = e[i][j], r = e[i][e[i].size() - 1 - j];
				l++;
				u = max(u, 2*j + 2 + daj(l, r));
			}
		}

		cout << max(u, daj(0, n)) << '\n';
	}
}