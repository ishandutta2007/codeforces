#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, k, x, y;
	cin >> n >> m >> k >> x >> y;

	vector<vector<ll> > ans(n, vector<ll>(m));

	if (n == 1) {
		ll full = k / m;
		for (int j = 0; j < m; ++j) {
			ans[0][j] = full;
		}
		k %= m;
		for (int j = 0; k < m && k; ++j) {
			++ans[0][j];
			--k;
		}
	} else {
		for (int j = 0; j < m && k; ++j) {
			ans[0][j] = 1;
			--k;
		}
		ll full = k / ((2 * n - 2) * m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 || i == n - 1) {
					ans[i][j] += full;
				} else {
					ans[i][j] += 2 * full;
				}
			}
		}
		k %= ((2 * n - 2) * m);
		int i = 1;
		int dir = 1;
		int j = 0;
		while (k) {
			++ans[i][j];
			++j;
			if (j == m) {
				j = 0;
				i += dir;
				if (i == n) {
					i = n - 2;
					dir = -1;
				}
				if (i < 0) {
					i = 2;
					dir = 1;
				}
			}
			--k;
		}
	}

	ll maxx = ans[0][0], minn = ans[0][0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			maxx = max(maxx, ans[i][j]);
			minn = min(minn, ans[i][j]);
		}
	}

	cout << maxx << " " << minn << " " << ans[x - 1][y - 1] << "\n";



}