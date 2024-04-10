#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[1005];
int up[1005][1005], dn[1005][1005], le[1005][1005], rt[1005][1005];
int zh[1005][1005], zv[1005][1005];

struct zvezda {
	int x, y, w;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] = string(".") + a[i] + '.';
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			up[i][j] = up[i-1][j] + 1;
			le[i][j] = le[i][j-1] + 1;

			if (a[i][j] != '*')
				up[i][j] = le[i][j] = 0;
		}

	for (int i=n; i>=1; i--)
		for (int j=m; j>=1; j--) {
			dn[i][j] = dn[i+1][j] + 1;
			rt[i][j] = rt[i][j+1] + 1;

			if (a[i][j] != '*')
				dn[i][j] = rt[i][j] = 0;
		}

	vector<zvezda> v;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int w = min({up[i-1][j], dn[i+1][j], le[i][j-1], rt[i][j+1]});

			if (w > 0 && a[i][j] == '*') {
				zv[i-w][j]++;
				zv[i+w+1][j]--;

				zh[i][j-w]++;
				zh[i][j+w+1]--;
				v.push_back({i, j, w});
				// cerr << "zvezda " << i << ' ' << j << ' ' << w << '\n';
			}
				
		}
	}

	bool bad = false;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			zh[i][j] += zh[i][j-1];
			zv[i][j] += zv[i-1][j];
			int z = zh[i][j] + zv[i][j];
			if ((z > 0) != (a[i][j] == '*'))
				bad = true;
		}
	}

	if (bad)
		return cout << -1, 0;

	cout << v.size() << '\n';
	for (auto u : v)
		cout << u.x << ' ' << u.y << ' ' << u.w << '\n';
}