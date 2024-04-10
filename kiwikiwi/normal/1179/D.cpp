#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define maxN 523456

vector<int> e[maxN];
i64 dp[maxN], ans = 1ll << 60;
int n, scnt[maxN];

i64 C2(i64 n) { return n * (n - 1) / 2; }

void dfs(int u, int f) {
	vector<pair<int, i64> > s;
	scnt[u] = 1;
	for (auto v : e[u]) {
		if (v == f) continue;
		dfs(v, u);
		scnt[u] += scnt[v];
		s.push_back(make_pair(scnt[v], dp[v]));
	}
	dp[u] = C2(scnt[u]);
	for (auto v : e[u]) {
		if (v == f) continue;
		dp[u] = min(dp[u], dp[v] + C2(scnt[u] - scnt[v]));
	}
	s.push_back(make_pair(0, 0));
	int m = s.size();
	sort(s.begin(), s.end());
	function<void(int, int, int, int)> solve = [&](int pl, int pr, int ql, int qr) {
		int mid = (pl + pr) / 2;
		i64 opt = 1ll << 60;
		int pos = -1;
		for (int i = ql; i <= qr; i++) {
			i64 cur = C2(n - s[i].first - s[mid].first) + s[i].second + s[mid].second;
			if (i <= mid) cur = 1ll << 59;
			if (cur < opt) {
				opt = cur;
				pos = i;
			}
		}
		ans = min(ans, opt);
		if (pl < mid) solve(pl, mid - 1, ql, pos);
		if (mid < pr) solve(mid + 1, pr, pos, qr);
	};
	solve(0, m - 1, 0, m - 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	printf("%lld\n", 2 * C2(n) - ans);
}