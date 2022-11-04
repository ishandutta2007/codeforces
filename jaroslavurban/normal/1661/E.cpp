#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const char F = '1';

void ProGamerMove() {
	int n; cin >> n;
	vector<string> f(3);
	for (auto& s : f) cin >> s;
	vector<vector<int>> vis(3, vector<int>(n));
	vector<int> mns, mxs;
	int cur = 1;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
			if (!vis[i][j] && f[i][j] == F) {
				queue<pair<int, int>> q; q.push({i, j});
				vis[i][j] = cur;
				int mn = j, mx = j;
				while (q.size()) {
					auto [y, x] = q.front(); q.pop();
					mn = min(mn, x);
					mx = max(mx, x);
					for (int dx = -1; dx <= 1; ++dx)
						for (int dy = -1; dy <= 1; ++dy)
							if (abs(dx) + abs(dy) == 1) {
								int nx = x + dx;
								int ny = y + dy;
								if (nx >= 0 && nx < n && ny >= 0 && ny <= 2 && !vis[ny][nx] && f[ny][nx] == F) {
									vis[ny][nx] = cur;
									q.push({ny, nx});
								}
							}
				}
				mns.push_back(mn);
				mxs.push_back(mx);
				++cur;
			}
	--cur;
//	for (auto vec : vis) {
//		for (int v : vec)
//			cout << v << " ";
//		cout << endl;
//	}
	sort(mns.begin(), mns.end());
	sort(mxs.begin(), mxs.end());
	auto calc = [&] (vector<string> f) {
		vector<int> res(n);
		for (int i = 0, j = 0; i < n; ++i) {
			j = max(j, i);
			while (j < n && f[0][j] == F && f[1][j] != F && f[2][j] == F) ++j;
			if (i == j && f[0][j] == F && f[1][j] == F && f[2][j] == F) res[i] = i;
			else if (j == n || !(f[0][j] == F && f[1][j] == F && f[2][j] == F)) {
				res[i] = n;
			} else res[i] = j;
		}
		return res;
	};
	auto mn = calc(f);
	for (auto& s : f) reverse(s.begin(), s.end());
	auto mnr = calc(f);
	reverse(mnr.begin(), mnr.end());
	for (int& v : mnr) v = n - v - 1;
	for (auto& s : f) reverse(s.begin(), s.end());
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; ++i) cnt[i + 1] = cnt[i] + !(f[0][i] == F && f[1][i] != F && f[2][i] == F);
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r, --l;
		int prv = lower_bound(mxs.begin(), mxs.end(), l) - mxs.begin();
		int aft = mns.end() - lower_bound(mns.begin(), mns.end(), r);
		int in = cur - prv - aft;
		int add = 0;
		if (vis[0][l] == vis[2][l] && vis[0][l] && !vis[1][l]) add += mn[l] >= r;
		if (vis[0][r - 1] == vis[2][r - 1] && vis[0][r - 1] && !vis[1][r - 1]) add += mnr[r - 1] < l;
		if (add == 2 && vis[0][l] == vis[0][r - 1]) add -= (cnt[l] == cnt[r]);
		cout << in + add << "\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}