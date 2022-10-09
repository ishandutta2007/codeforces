#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct node {
	node* nx[4];
	int v;
};

int n, m, q;
node a[1005][1005];

node* setaj(int x, int y) {
	auto it = &a[0][0];
	while (x--)
		it = it->nx[0];
	while (y--)
		it = it->nx[1];
	return it;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j].v;
		}
	}
	n += 2;
	m += 2;

	for (int i=0; i<n-1; i++) {
		for (int j=0; j<m; j++) {
			a[i][j].nx[0] = &a[i+1][j];
			a[i+1][j].nx[2] = &a[i][j];
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m-1; j++) {
			a[i][j].nx[1] = &a[i][j+1];
			a[i][j+1].nx[3] = &a[i][j];
		}
	}

	while (q--) {
		int x, y, c, d, h, w;
		cin >> x >> y >> c >> d >> h >> w;

		auto it = setaj(x, y);
		auto jt = setaj(c, d);

		vector<pair<node**, node**>> sw;

		for (int dir=0; dir<4; dir++) {
			for (int t=0; t<(dir%2?w:h); t++) {
				int u = (dir+3) & 3, v = (dir+1) & 3;
				sw.emplace_back(&it->nx[u], &jt->nx[u]);
				sw.emplace_back(&it->nx[u]->nx[v], &jt->nx[u]->nx[v]);
				if (t < (dir%2?w:h)-1)
					it = it->nx[dir], jt = jt->nx[dir];
			}
		}

		for (auto [x, y] : sw)
			swap(*x, *y);
	}

	for (int i=1; i<=n-2; i++) {
		auto it = setaj(i, 1);
		for (int j=0; j<m-2; j++)
			cout << it->v << " \n"[j == m-3], it = it->nx[1];
	}
}