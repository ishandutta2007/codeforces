#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int N = 100100, M = log2(N) + 2;
ll dp[M][N][2][2];

struct P {
	int i, j;
};

ll dist(P a, P b) { return abs(a.i - b.i) + abs(a.j - b.j); }

int lvl(P a) { return max(a.i, a.j); }

void ProGamerMove() {
	int n; cin >> n;
	vector<P> doors[2];
	doors[0].resize(n - 1);
	doors[1].resize(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> doors[0][i].i >> doors[0][i].j >> doors[1][i].i >> doors[1][i].j;
		--doors[0][i].i;
		--doors[0][i].j;
		--doors[1][i].i;
		--doors[1][i].j;
	}
	for (int i = 0; i < n - 2; ++i) {
		auto a = doors[0][i];
		auto b = doors[1][i];
		auto c = doors[0][i + 1];
		auto d = doors[1][i + 1];
		dp[0][i][0][0] = 1 + dist(P{a.i + 1, a.j}, c);
		dp[0][i][1][1] = 1 + dist(P{b.i, b.j + 1}, d);
		dp[0][i][0][1] = min(1 + dist(P{a.i + 1, a.j}, d), dp[0][i][1][1] + dist(a, b));
		dp[0][i][1][0] = min(1 + dist(P{b.i, b.j + 1}, c), dp[0][i][0][0] + dist(a, b));
	}
	for (int ln = 1; ln < M; ++ln) {
		for (int i = 0, j = 1 << (ln - 1); j < n - 1; ++i, ++j) {
			dp[ln][i][0][0] = min(dp[ln - 1][i][0][0] + dp[ln - 1][j][0][0], dp[ln - 1][i][0][1] + dp[ln - 1][j][1][0]);
			dp[ln][i][0][1] = min(dp[ln - 1][i][0][1] + dp[ln - 1][j][1][1], dp[ln - 1][i][0][0] + dp[ln - 1][j][0][1]);
			dp[ln][i][1][0] = min(dp[ln - 1][i][1][0] + dp[ln - 1][j][0][0], dp[ln - 1][i][1][1] + dp[ln - 1][j][1][0]);
			dp[ln][i][1][1] = min(dp[ln - 1][i][1][1] + dp[ln - 1][j][1][1], dp[ln - 1][i][1][0] + dp[ln - 1][j][0][1]);
		}
	}
	int m; cin >> m;
	while (m--) {
		P s, t; cin >> s.i >> s.j >> t.i >> t.j, --s.i, --s.j, --t.i, --t.j;
		if (lvl(s) == lvl(t)) cout << dist(s, t) << '\n';
		else {
			if (lvl(s) > lvl(t)) swap(s, t);
			vector<ll> mdp = {dist(s, doors[0][lvl(s)]), dist(s, doors[1][lvl(s)])};
			int jmp = lvl(t) - lvl(s) - 1, lv = lvl(s);
			for (int i = M - 1; i >= 0; --i)
				if ((1 << i) <= jmp) {
					ll o0 = mdp[0];
					mdp[0] = min(mdp[0] + dp[i][lv][0][0], mdp[1] + dp[i][lv][1][0]);
					mdp[1] = min(mdp[1] + dp[i][lv][1][1], o0 + dp[i][lv][0][1]);
					lv += 1 << i;
					jmp -= 1 << i;
				}
			assert(lv + 1 == lvl(t));
			cout << min(mdp[0] + 1 + dist(P{doors[0][lv].i + 1, doors[0][lv].j}, t), mdp[1] + 1 + dist(P{doors[1][lv].i, doors[1][lv].j + 1}, t)) << '\n';
		}
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