#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m, k;
int x[505], y[505];

int x_koord[1005], y_koord[1005], kk, kkx, kky;

int z[1055][1055];

bool popuni(int sz) {
	kk = 0;
	for (int i=1; i<=k; i++) {

		int xl = x[i] - sz;
		if (xl < 1) {
			xl = 1;
		}

		int xr = x[i] + sz + 1;
		if (xr > n+1) {
			xr = n+1;
		}

		int yl = y[i] - sz;
		if (yl < 1) {
			yl = 1;
		}

		int yr = y[i] + sz + 1;
		if (yr > m+1) {
			yr = m+1;
		}

		kk++;
		x_koord[kk] = xl;
		y_koord[kk] = yl;
		kk++;
		x_koord[kk] = xr;
		y_koord[kk] = yr;
	}

	kk++;
	x_koord[kk] = 1;
	y_koord[kk] = 1;
	kk++;
	x_koord[kk] = n+1;
	y_koord[kk] = m+1;

	sort(x_koord+1, x_koord+kk+1);
	kkx = unique(x_koord+1, x_koord+kk+1) - x_koord - 1;

	sort(y_koord+1, y_koord+kk+1);
	kky = unique(y_koord+1, y_koord+kk+1) - y_koord - 1;

	memset(z, 0, sizeof(z));

	for (int i=1; i<=k; i++) {
		int xl = x[i] - sz;
		if (xl < 1) {
			xl = 1;
		}

		int xr = x[i] + sz + 1;
		if (xr > n+1) {
			xr = n+1;
		}

		int yl = y[i] - sz;
		if (yl < 1) {
			yl = 1;
		}

		int yr = y[i] + sz + 1;
		if (yr > m+1) {
			yr = m+1;
		}

		xl = lower_bound(x_koord+1, x_koord+kkx+1, xl) - x_koord;
		xr = lower_bound(x_koord+1, x_koord+kkx+1, xr) - x_koord;
		yl = lower_bound(y_koord+1, y_koord+kky+1, yl) - y_koord;
		yr = lower_bound(y_koord+1, y_koord+kky+1, yr) - y_koord;

		z[xl][yl]++;
		z[xl][yr]--;
		z[xr][yl]--;
		z[xr][yr]++;
	}

	int loy = 2e9, hiy = -2e9, lox = 2e9, hix = -2e9;
	int any = 0;

	for (int i=1; i<kkx; i++) {
		for (int j=1; j<kky; j++) {
			z[i][j] += z[i-1][j] + z[i][j-1] - z[i-1][j-1];
			if (z[i][j] == 0) {
				any = 1;
				lox = min(lox, x_koord[i]);
				hix = max(hix, x_koord[i+1]);
				loy = min(loy, y_koord[j]);
				hiy = max(hiy, y_koord[j+1]);
			}
		}
	}

	if (!any) {
		return true;
	}

	cerr << sz << ' ' << lox << ' ' << hix << ' ' << loy << ' ' << hiy << '\n';

	return max(hiy-loy, hix-lox) / 2 <= sz;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=k; i++) {
		cin >> x[i] >> y[i];
	}

	int l = 0, r = 1e9, o = 1e9;
	while (l <= r) {
		int m = (l+r) / 2;
		if (popuni(m)) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}

	cout << o;


}