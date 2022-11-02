#include <iostream>
#include <algorithm>
using namespace std;

int ep[300009][21];
long long cc[300009], a[300009], c[300009], at[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q >> a[1] >> c[1]; cc[1] = a[1];
	at[1] = a[1];
	for (int i = 2; i <= q + 1; i++) {
		int t; cin >> t;
		if (t == 1) {
			int p; cin >> p >> a[i] >> c[i]; p++;
			at[i] = a[i];
			cc[i] = cc[p] + a[i];
			ep[i][0] = p;
			for (int j = 0; j < 20; j++)
				ep[i][j + 1] = ep[ep[i][j]][j];
		}
		else {
			int v; long long w; cin >> v >> w; v++;
			int pv = v;
			for (int j = 20; j >= 0; j--)
				if (a[ep[pv][j]] > 0)
					pv = ep[pv][j];
			long long r = cc[ep[pv][0]] + at[pv] - a[pv];
			pv = v;
			for (int j = 20; j >= 0; j--)
				if (cc[ep[pv][j]] - r >= w)
					pv = ep[pv][j];
			long long ans = 0, ansc = 0;
			for (int j = ep[pv][0]; j > 0 && a[j] > 0; j = ep[j][0]) {
				ans += a[j] * c[j];
				ansc += a[j];
				w -= a[j];
				a[j] = 0;
			}
			w = min(a[pv], w);
			a[pv] -= w;
			ans += w * c[pv];
			ansc += w;
			cout << ansc << " " << ans << endl;
		}
	}
	return 0;
}