#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct qry {
	int a, b, c, d;
	ll v;
} g[2222]; int bsz;

ll e[1111][1111], f[1111][1111];
int n, q;

bool ok(int x) {
	return x >= 0 && (x & 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			ll v = e[a-1][b-1] ^ e[c][d] ^ e[a-1][d] ^ e[c][b-1];
			for (int i=0; i<bsz; i++) {
				if (ok(min(c, g[i].c) - max(a, g[i].a) + 1) &&
				    ok(min(d, g[i].d) - max(b, g[i].b) + 1))
				{
					v ^= g[i].v;
				}
			}
			cout << v << '\n';
		} else {
			int a, b, c, d;
			ll v;
			cin >> a >> b >> c >> d >> v;
			g[bsz++] = {a, b, c, d, v};
			if (bsz == n) {
				for (int i=1; i<=n; i++)
					for (int j=1; j<=n; j++)
						f[i][j] = 0;
				for (int i=0; i<n; i++) {
					auto [a, b, c, d, v] = g[i];
					c++, d++;
					f[a][b] ^= v;
					f[c][d] ^= v;
					f[a][d] ^= v;
					f[c][b] ^= v;
				}
				for (int i=3; i<=n; i++)
					for (int j=1; j<=n; j++)
						f[i][j] ^= f[i-2][j];

				for (int i=1; i<=n; i++)
					for (int j=3; j<=n; j++)
						f[i][j] ^= f[i][j-2];

				for (int i=1; i<=n; i++)
					for (int j=1; j<=n; j++)
						e[i][j] ^= f[i][j];
				bsz = 0;
			}
		}
	}
}