#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[2005][2005];
ll z[2][2][2005][2005];
ll w[2005][2005];

tuple<int, int, int> params(int d) {
	if (d == 0)
		return {1, n+1, 1};
	else
		return {n, 0, -1};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> a[i][j];

	for (int dx=0; dx<2; dx++) {
		for (int dy=0; dy<2; dy++) {
			auto [px, qx, rx] = params(dx);
			auto [py, qy, ry] = params(dy);
			for (int x=px; x!=qx; x+=rx)
				for (int y=py; y!=qy; y+=ry)
					z[dx][dy][x][y] = a[x][y] +  z[dx][dy][x-rx][y-ry];
		}
	}

	int ei = 0, ej = 0, oi = 0, oj = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			ll v = z[0][0][i][j] + z[0][1][i][j] + z[1][0][i][j] + z[1][1][i][j];
			v -= 3*a[i][j];
			w[i][j] = v;
			if ((i+j) % 2 == 0) {
				if (v >= w[ei][ej]) {
					ei = i;
					ej = j;
				}
			} else {
				if (v >= w[oi][oj]) {
					oi = i;
					oj = j;
				}
			}
		}
	}
	cout << w[ei][ej] + w[oi][oj] << '\n';
	cout << ei << ' ' << ej << ' ' << oi << ' ' << oj << '\n';
}