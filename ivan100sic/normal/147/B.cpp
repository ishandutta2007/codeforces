#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

int n;
vvi d[9];

vvi mnozi(const vvi& a, const vvi& b) {
	if (b.size() == 0) {
		return a;
	}

	vvi c = a;
	for (int i=1; i<=n; i++) {
		for (int k=1; k<=n; k++) {

			for (int j=1; j<=n; j++) {
				c[i][k] = min(c[i][k], a[i][j] + b[j][k]);
			}
		}
	}
	
	return c;
}

bool imaneg(const vvi& a) {
	for (int i=1; i<=n; i++) {
		if (a[i][i] < 0) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int m;
	cin >> n >> m;

	d[0].resize(n+1, vector<int>(n+1, 1e9));

	while (m--) {
		int x, y, cf, cb;
		cin >> x >> y >> cf >> cb;
		d[0][x][y] = -cf;
		d[0][y][x] = -cb;
	}

	for (int i=1; i<9; i++) {
		d[i] = mnozi(d[i-1], d[i-1]);
	}

	vvi xx;
	int sol = 0, curr = 0;

	for (int bit=8; bit>=0; bit--) {
		auto yy = mnozi(d[bit], xx);
		if (imaneg(yy)) {
			sol = curr + (1 << bit);
		} else {
			xx = yy;
			curr += 1 << bit;
		}
	}

	cout << sol << '\n';




}