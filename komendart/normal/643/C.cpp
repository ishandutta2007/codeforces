#include <bits/stdc++.h>

using namespace std;


int n, k;




vector<long double> a, qwe, asd, zxc;
vector<vector<long double> > dp;

long double ret(int l, int r) {
	return ((zxc[r] - zxc[l - 1]) - (asd[r] - asd[l - 1]) * (qwe[l - 1]));
}

void go(int i, int l, int r, int L, int R) {
	if (l > r)
		return;

	int qq = -1;
	int m = (l + r) / 2;
	for (int j = max(L, 1); j < min(R, m) + 1; j ++) {
		if (dp[i][m] > dp[i - 1][j - 1] + ret(j, m)) {
			dp[i][m] = dp[i - 1][j - 1] + ret(j, m);
			qq = j;
		}
	}
	go(i, l, m - 1, L, qq),	go(i, m + 1, r, qq, R);
}

void init(){

	qwe.resize(n + 5);
	asd.resize(n + 5);
	zxc.resize(n + 5);

	for(int i = 0; i < n; i ++) {
		qwe[i + 1] = qwe[i] + a[i];
		zxc[i + 1] = zxc[i] + qwe[i + 1] / a[i];
		asd[i + 1] = asd[i] + 1 / a[i];
	}
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;

	a.resize(n + 5);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	init();

	dp.assign(k + 5, vector<long double> (n + 5, 1e23));
	dp[0][0] = 0;

	for(int i = 1; i < k + 1; i ++) {
		go(i, 1, n, 1, n);
	}

	cout.precision(10);
	cout << fixed << dp[k][n];
}