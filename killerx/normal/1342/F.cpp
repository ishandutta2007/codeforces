#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, a[15];
std::pair <int, int> vec[1 << 15];
std::pair <int, int> dp[16][16][1 << 15];
int id[1 << 15];
int cntbits[1 << 15];
std::vector <std::pair <int, int> > ops;
bool hav[15];

int real(int x) {
	int ans = 0;
	rep(i, x + 1) ans += hav[i];
	return ans;
}

void print(int i, int j, int S) {
	if (i == 0) return ;
	int s = vec[dp[i][j][S].first].second;
	int ps = dp[i][j][S].second;
	print(ps, j - (cntbits[s] - 1), S ^ s);
	rep(x, n) if ((s >> x & 1) && x != ps) ops.push_back({x, ps});
}

void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, 1 << n) {
		int s = 0;
		rep(j, n) if (i >> j & 1) s += a[j];
		vec[i] = {s, i};
	}
	std::sort(vec, vec + (1 << n));
	rep(i, 1 << n) id[vec[i].second] = i;
	rep(i, 1 << n) cntbits[i] = i ? cntbits[i ^ (i & -i)] + 1 : 0;
	rep(i, n + 1) rep(j, n + 1) rep(S, 1 << n) dp[i][j][S] = {0x3f3f3f3f, -1};
	dp[0][0][0] = {0, 0};
	int ful = (1 << n) - 1;
	rep(i, n) rep(j, n + 1) rep(S, 1 << n) if (dp[i][j][S].first < 1 << n) {
		dp[i + 1][j][S] = std::min(dp[i + 1][j][S], dp[i][j][S]);
		if (!(S >> i & 1)) for (int sub = ful ^ S ^ 1 << i; ; sub = (sub - 1) & (ful ^ S ^ 1 << i)) {
			int usd = cntbits[sub];
			int las = sub | 1 << i;
			std::pair <int, int> &pr = dp[i + 1][j + usd][S | las];
			if (vec[dp[i][j][S].first].first < vec[id[las]].first)
				pr = std::min(pr, {id[las], i});
			if (sub == 0) break;
		}
		// eprintf("%d %d %d %d\n", i, j, S, dp[i][j][S]);
	}
	int j = 0;
	while (dp[n][j][(1 << n) - 1].first >= (1 << n)) ++ j;
	printf("%d\n", j);
	ops.clear();
	print(n, j, (1 << n) - 1);
	rep(i, n) hav[i] = 1;
	rep(i, ops.size()) {
		int u = ops[i].first;
		int v = ops[i].second;
		printf("%d %d\n", real(u), real(v));
		hav[u] = 0;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}