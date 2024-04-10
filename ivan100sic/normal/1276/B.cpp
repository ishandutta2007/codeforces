#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[200005];
int c[2][200005];

void bfs(int a, int* c) {
	fill(c+1, c+n+1, 0);
	int cc = 0;
	for (int i=1; i<=n; i++) {
		if (i == a)
			continue;
		if (!c[i]) {
			c[i] = ++cc;
			basic_string<int> q = {i};
			size_t qs = 0;
			while (qs != q.size()) {
				int x = q[qs++];
				for (int y : e[x]) {
					if (y == a || c[y])
						continue;
					c[y] = c[x];
					q += y;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> n >> m >> a >> b;
		fill(e+1, e+n+1, basic_string<int>());
		for (int i=0; i<m; i++) {
			int x, y;
			cin >> x >> y;
			e[x] += y;
			e[y] += x;
		}

		bfs(a, c[0]);
		bfs(b, c[1]);

		ll p=0, q=0;
		for (int i=1; i<=n; i++) {
			if (i == a || i == b)
				continue;
			p += c[0][i] != c[0][b];
			q += c[1][i] != c[1][a];
		}
		cout << p*q << '\n';
	}
}