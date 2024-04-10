#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<pair<int, int>> e[300005];
int put[300005], gde[300005], h[300005], flen[300005];

int pre[300005], steps;

ll hb[300005], mxb[300005];

void dfs(int x, int p, int l) {
	pre[x] = p;
	flen[x] = l;
	for (auto ee : e[x]) {
		if (ee.first != p) {
			dfs(ee.first, x, ee.second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> n >> q;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}

	dfs(n, n, 0);
	{
		int t = 1;
		do {
			put[++steps] = t;
			gde[t] = steps;
			t = pre[t];
		} while (t != n);
		put[++steps] = n;
		gde[n] = steps;
	}

	bool degenerik = false;

	for (int i=1; i<=steps; i++) {
		// koliko ima suseda koji nisu na putu, i da li su oni listovi
		int x = put[i];
		int c = 0;
		for (auto ee : e[x]) {
			int y = ee.first;
			if (gde[y])
				continue;
			if (e[y].size() > 1)
				degenerik = true;
			h[i] = ee.second;
			c++;
		}
		if (c > 1)
			degenerik = true;
	}

	ll sum = 0, samoput;

	for (int i=steps; i>1; i--) {
		hb[i] = sum;
		sum += flen[put[i-1]];
		mxb[i] = max(mxb[i-1], hb[i] + h[i]);
	}
	samoput = sum;

	ll dp = 0;
	sum = 0;
	for (int i=1; i<steps; i++) {
		// ja + dva unapred (bilo sta)

		// cerr << i << " : sum : " << sum << '\n';

		if (i+2 <= steps) {
			dp = max(dp, sum + h[i] + mxb[i+2]);
		}

		if (h[i] > 0 || h[i+1] > 0)
			dp = max(dp, sum + h[i] + h[i+1] + hb[i+1]);

		// dodaj na sumu
		sum += flen[put[i]];
	}

	cerr << "steps: " << steps << '\n';
	cerr << "dp: " << dp << '\n';

	while (q--) {
		int x;
		cin >> x;
		if (degenerik) {
			cout << samoput;
		} else {
			cout << min(dp + x, samoput);
		}
		cout << '\n';
	}
}