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
		int n, sol = 0;
		vector<int> g(20), vis(20);
		vector<basic_string<int>> h(20);
		string a, b;
		cin >> n >> a >> b;
		for (int i=0; i<n; i++) {
			if (a[i] != b[i]) {
				int u = a[i] - 'a';
				int v = b[i] - 'a';
				g[u] |= 1 << v;
			}
		}
		n = 20;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (g[i] & (1 << j)) {
					h[i] += j;
					h[j] += i;
				}
			}
		}

		for (int i=0; i<n; i++) {
			if (!vis[i]) {
				basic_string<int> q = {i};
				vis[i] = 1;
				size_t qs = 0;
				while (qs < q.size()) {
					int x = q[qs++];
					for (int y : h[x]) {
						if (!vis[y]) {
							vis[y] = 1;
							q += y;
						}
					}
				}

				int k = q.size();
				vector<int> e(k);

				for (int u=0; u<k; u++) {
					for (int v=0; v<k; v++) {
						if (g[q[u]] & (1 << q[v])) {
							e[u] |= 1 << v;
						}
					}
				}

				// dp
				vector<int> d(1 << k, 1e9);
				d[0] = 0;
				for (int mask=1; mask<(1<<k); mask++) {
					for (int u=0; u<k; u++) {
						if (!(mask & (1 << u))) {
							continue;
						}
						int mask2 = mask - (1 << u);
						int w = 1 + !!(mask & e[u]);
						d[mask] = min(d[mask], d[mask2] + w);
					}
				}

				sol += d[(1<<k)-1]-1;
			}
		}

		cout << sol << '\n';
	}
}