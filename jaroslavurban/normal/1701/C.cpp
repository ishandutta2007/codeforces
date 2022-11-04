#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<int> cnt(n);
	for (int v, i = 0; i < m; ++i) cin >> v, ++cnt[--v];
	vector<vector<int>> working(2, vector<int>(n));
	int t = 0;
	while (accumulate(cnt.begin(), cnt.end(), 0) || count(working[0].begin(), working[0].end(), 1)) {
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i) if (cnt[i]) q.push({cnt[i] - 1, i});
		for (int i = 0; i < n; ++i) if (!working[0][i] && !cnt[i]) {
			while (q.size() && q.top().first == 0) q.pop();
			if (q.size()) {
				auto [x, y] = q.top(); q.pop();
				working[1][i] = 1;
				--cnt[y];
				q.push({x - 1, y});
			}
		} else if (cnt[i]) --cnt[i];
		swap(working[0], working[1]);
		working[1].assign(n, 0);
		++t;
	}
	cout << t << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}