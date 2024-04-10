#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, h;
int x[2005];
int reach_r[2005];
int reach_l[2005];

ld dp[2005][2005][2][2], p, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h >> p;
	q = 1 - p;
	for (int i=1; i<=n; i++)
		cin >> x[i];
	sort(x+1, x+n+1);
	x[0] = -321321321;
	x[n+1] = 321321321;

	for (int i=1; i<=n; i++)
		if (x[i] - x[i-1] < h)
			reach_l[i] = reach_l[i-1];
		else
			reach_l[i] = i;

	reach_r[n] = n;
	for (int i=n-1; i>=1; i--)
		if (x[i+1] - x[i] < h)
			reach_r[i] = reach_r[i+1];
		else
			reach_r[i] = i;

	for (int l=n; l>=1; l--) {
		for (int r=l; r<=n; r++) {
			for (int ul=0; ul<2; ul++) {
				for (int ur=0; ur<2; ur++) {
					auto& d = dp[l][r][ul][ur];
					int wl = min(h, x[l] - x[l-1] - ul*h);
					int wr = min(h, x[r+1] - x[r] - ur*h);
					int y;
					// L pada L
					d += p/2 * (dp[l+1][r][0][ur] + wl);
					// R pada R
					d += q/2 * (dp[l][r-1][ul][0] + wr);
					// L pada R
					y = reach_r[l];
					if (y < r) {
						d += q/2 * (dp[y+1][r][1][ur] + (x[y]-x[l]+h));
					} else {
						d += q/2 * (x[r]-x[l]+wr);
					}
					// R pada L
					y = reach_l[r];
					if (y > l) {
						d += p/2 * (dp[l][y-1][ul][1] + (x[r]-x[y]+h));
					} else {
						d += p/2 * (x[r]-x[l]+wl);
					}
				}
			}
		}
	}

	cout.precision(20);
	cout << fixed << dp[1][n][0][0] << '\n';
}