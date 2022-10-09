#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
};

#define tm siofdjsodi

int h, t, r, n, m;
int w[205][205], unc[205][205], tm[205][205];
basic_string<pt> e[205][205], f[205][205], qu;
pt hd[205], td[205];

void ae(int i, int j, int u, int v) {
	if (u + v > r)
		return;
	e[i][j] += {u, v};
	f[u][v] += {i, j};
	unc[i][j]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> h >> t >> r;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> hd[i].x >> hd[i].y;
	cin >> m;
	for (int i=1; i<=m; i++)
		cin >> td[i].x >> td[i].y;

	// grane
	for (int i=0; i<=r; i++) {
		for (int j=0; i+j<=r; j++) {
			// seci glave
			for (int x=1; x<=min(i, n); x++) {
				int u = i-x+hd[x].x;
				int v = j  +hd[x].y;

				ae(i, j, u, v);
			}

			for (int y=1; y<=min(j, m); y++) {
				int u = i  +td[y].x;
				int v = j-y+td[y].y;

				ae(i, j, u, v);
			}
		}
	}

	{
		// nadji sve keceve
		w[0][0] = 1;
		qu += pt{0, 0};
		size_t qs = 0;
		while (qs != qu.size()) {
			auto [i, j] = qu[qs++];
			for (auto [x, y] : f[i][j]) {
				if (w[x][y] == 0) {
					w[x][y] = 1;
					tm[x][y] = tm[i][j] + 1;
					qu += {x, y};
				}
			}
		}
	}

	// nadji nesrecne -1
	qu = {};

	for (int i=0; i<=r; i++) {
		for (int j=0; i+j<=r; j++) {
			if (w[i][j] == 0 && unc[i][j] == 0) {
				qu += {i, j};
				// cerr << "jadnik " << i << ' ' << j << '\n';
			}
		}
	}

	size_t qs = 0;
	while (qs != qu.size()) {
		auto [i, j] = qu[qs++];
		// neka dobra grana ima li?
		int q = 0;
		for (auto [x, y] : e[i][j]) {
			q = max(q, tm[x][y]);
		}

		w[i][j] = -1;
		tm[i][j] = q + 1;

		for (auto [x, y] : f[i][j]) {
			if (!--unc[x][y]) {
				qu += {x, y};
			}
		}
	}

	if (w[h][t] == 1) {
		cout << "Ivan\n";
		cout << tm[h][t] << '\n';
	} else if (w[h][t] == -1) {
		cout << "Zmey\n";
		cout << tm[h][t] << '\n';
	} else {
		cout << "Draw\n";
	}
}