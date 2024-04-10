#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	vector<pair<int, int>> diff = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
	unordered_map<char, int> dy = {{'U', +1}, {'D', -1}};
	unordered_map<char, int> dx = {{'L', +1}, {'R', -1}};
	int n, m; cin >> n >> m;
	int p, qq; cin >> p >> qq;
	vector<string> f(n);
	for (auto& s : f) cin >> s;
	vector<vector<ll>> price(n, vector<ll>(m, (ll)1e18));
//	vector<vector<bool>> done(n, vector<ll>(m));
	priority_queue<tuple<ll, int, int>> q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (f[i][j] == '.') {
				price[i][j] = 0;
//				done[i][j] = true;
				q.push({0, i, j});
			}
	while (q.size()) {
		auto [d, i, j] = q.top(); q.pop();
		d *= -1;
		if (d > price[i][j]) continue;
//		done[i][j] = true;
		for (auto [di, dj] : diff) {
			int ni = di + i, nj = j + dj;
			if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
//				if (done[ni][nj]) {
//					cout << price[i][j] + price[ni][nj] << '\n';
//					return;
//				}
				if (f[ni][nj] != '#' && (di + dy[f[ni][nj]] != 0 || dj + dx[f[ni][nj]] != 0)) {
					int nni = ni + dy[f[ni][nj]];
					int nnj = nj + dx[f[ni][nj]];
					int cost = abs(i - nni) == 2 || abs(j - nnj) == 2 ? qq : p;
					if (price[nni][nnj] > price[i][j] + cost) {
						price[nni][nnj] = price[i][j] + cost;
						q.push({-price[nni][nnj], nni, nnj});
					}
				}
			}
		}
	}
//	for (int i = 0; i < n; ++i, cerr << endl)
//		for (int j = 0; j < m; ++j)
//			cerr << price[i][j] << ' ';
	ll res = LLONG_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m - 1; ++j)
			res = min(res, price[i][j] + price[i][j + 1]);
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m; ++j)
			res = min(res, price[i][j] + price[i + 1][j]);
	cout << (res < 1e18 ? res : -1) << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	// cin >> tc;
	while (tc--) ProGamerMove();
}