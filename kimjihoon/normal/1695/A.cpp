#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1000000009;

int mx[49][49][49][49], a[49][49];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int pi = i; pi < n; pi++)
					for (int pj = j; pj < m; pj++) {
						mx[i][j][pi][pj] = a[pi][pj];
						if (i < pi) mx[i][j][pi][pj] = max(mx[i][j][pi][pj], mx[i][j][pi - 1][pj]);
						if (j < pj) mx[i][j][pi][pj] = max(mx[i][j][pi][pj], mx[i][j][pi][pj - 1]);
					}
		int ans = n * m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int r = inf;
				bool f = true;
				for (int pi = 0; pi < n - i; pi++)
					for (int pj = 0; pj < m - j; pj++) {
						int t = mx[pi][pj][pi + i][pj + j];
						if (r == inf) r = t;
						else if (r != t) {
							f = false;
							break;
						}
					}
				if (f) ans = min(ans, (i + 1) * (j + 1));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}