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
		int n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		a--, b--, c--;

		vector<int> p(m);
		for (int i=0; i<m; i++)
			cin >> p[i];
		sort(begin(p), end(p));

		vector<basic_string<int>> e(n);
		for (int i=0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			e[u] += v, e[v] += u;
		}

		vector<ll> q(m+1);
		for (int i=0; i<m; i++)
			q[i+1] = q[i] + p[i];

		vector<int> d[3];

		for (int i=0; i<3; i++) {
			int x = i == 0 ? a : (i == 1 ? b : c);
			d[i].resize(n, -1);
			d[i][x] = 0;
			basic_string<int> q = {x};
			size_t qs = 0;
			while (qs != q.size()) {
				int x = q[qs++];
				for (int y : e[x]) {
					if (d[i][y] == -1) {
						d[i][y] = d[i][x] + 1;
						q += y;
					}
				}
			}
		}

		ll z = 1e18;

		for (int i=0; i<n; i++) {
			int a = d[0][i];
			int b = d[1][i];
			int c = d[2][i];
			if (a+b+c > m)
				continue;
			z = min(z, q[a+b+c] + q[b]);
		}

		cout << z << '\n';
	}
}