#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	int mxb = 0, mng = (int)1e9;

	long long sumg = 0;
	vector<int> b(n), g(m);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] > mxb)
			mxb = b[i];

	}

	int cntg = 0;

	for (int i = 0;  i < m; i++) {
		cin >> g[i];
		if (g[i] != mxb) {
			cntg++;
			sumg += g[i];
		}
		if (g[i] < mng)
			mng = g[i];
	}

	if (mxb > mng) {
		cout << -1;
		return 0;
	}

	sort(b.begin(), b.end());

	long long ans = 0;

	for (int i = 0; i + 2 < n; i++) {
		ans += 1ll * b[i] * m;
	}
	if (cntg == m) {
		ans += 1ll * b[n - 2] * (m - 1);
		ans += 1ll * b[n - 1] * 1;	

		ans += sumg;
	} else {
		ans += 1ll * b[n - 2] * m;
		ans += sumg + 1ll * (m - cntg) * b[n - 1];
	}

	cout << ans;
	return 0;
}