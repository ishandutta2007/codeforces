#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1005][1005], b[1005][1005], z[1005][1005];
int n;

double dp[1005][1005];
bool prePrva[1005][1005];

pair<int, string> resiKlasik() {

	double l = 0.0, r = 1.0;
	int best = 123123123, steps = 36;
	string put;

	while (steps--) {
		double m = (l+r) / 2;

		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {

				dp[i][j] = 1e30;

				if (i > 1) {
					if (dp[i-1][j] < dp[i][j]) {
						prePrva[i][j] = true;
						dp[i][j] = dp[i-1][j];
					}
				}

				if (j > 1) {
					if (dp[i][j-1] < dp[i][j]) {
						prePrva[i][j] = false;
						dp[i][j] = dp[i][j-1];
					}
				}

				if (i == 1 && j == 1)
					dp[i][j] = 0;

				dp[i][j] += a[i][j] * m + b[i][j] * (1 - m);
			}
		}

		// rek. put
		string p;
		int i = n, j = n;
		while (i + j > 2) {
			p += prePrva[i][j] ? "D" : "R";
			if (prePrva[i][j])
				i--;
			else
				j--;
		}

		reverse(p.begin(), p.end());

		// izracunaj stvarnu cenu puta
		int ax = 0, bx = 0;
		i = 1, j = 1;

		ax += a[1][1];
		bx += b[1][1];

		for (char x : p) {
			if (x == 'D')
				i++;
			else
				j++;

			ax += a[i][j];
			bx += b[i][j];
		}

		int vr = min(ax, bx);
		if (vr < best) {
			best = vr;
			put = p;
		}

		if (ax < bx) {
			l = m;
		} else {
			r = m;
		}
	}

	return {best, put};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int zx = -1, zy = -1;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			int x;
			cin >> x;
			if (x == 0) {
				a[i][j] = 32;
				b[i][j] = 32;
				z[i][j] = 1;
				zx = i;
				zy = j;
			} else {
				while (x % 2 == 0)
					a[i][j]++, x /= 2;
				while (x % 5 == 0)
					b[i][j]++, x /= 5;
			}
		}
	}

	pair<int, string> sol = resiKlasik();

	if (sol.first > 1 && zx != -1) {
		string s = string(zx-1, 'D') + string(zy-1, 'R')
			+ string(n-zx, 'D') + string(n-zy, 'R');

		sol = {1, s};
	}

	cout << sol.first << '\n' << sol.second << '\n';
}