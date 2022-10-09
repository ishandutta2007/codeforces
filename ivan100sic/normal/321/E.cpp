#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int dp[805][4005];
int a[4005][4005];

int cost(int l, int r) {
	l--;
	return a[l][l] + a[r][r] - a[l][r] - a[r][l];
}

void solve(int layer, int l, int r, int ql, int qr) {
	if (l > r) return;
	int m = (l+r) >> 1;
	int qm = ql;
	int v = dp[layer-1][ql] + cost(ql+1, m);
	for (int i=ql+1; i<=qr; i++) {
		int vv = dp[layer-1][i] + cost(i+1, m);
		if (vv < v) {
			v = vv;
			qm = i;
		}
	}
	dp[layer][m] = v;
	solve(layer, l, m-1, ql, qm);
	solve(layer, m+1, r, qm, qr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	string lajna;
	getline(cin, lajna);

	for (int i=1; i<=n; i++) {
		getline(cin, lajna);
		for (int j=1; j<=n; j++) {
			a[i][j] = lajna[2*j-2] - '0';
		}
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			a[i][j] += a[i-1][j];

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			a[i][j] += a[i][j-1];

	memset(dp, 63, sizeof(dp));
	dp[0][0] = 0;

	for (int i=1; i<=k; i++) {
		solve(i, 1, n, 0, n-1);
	}

	cout << dp[k][n]/2 << '\n';
}