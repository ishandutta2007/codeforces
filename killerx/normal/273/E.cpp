#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1e9 + 7;

struct range {
	int l, r, c;
};

std::vector <range> rngs;

inline void init();

inline int s1(int n) { return (1LL * n * (n - 1) / 2) % mod; }

int main() {
	init();
	int n, p;
	scanf("%d %d", &n, &p);
	int cnt[3] = {0};
	rep(i, rngs.size()) {
		int l = rngs[i].l, r = rngs[i].r, c = rngs[i].c;
		r = std::min(r, p);
		if (l < r) {
			int ss = (s1(r) + mod - s1(l)) % mod;
			cnt[c] = (cnt[c] + 1LL * (r - l) * p) % mod;
			cnt[c] = (cnt[c] + mod - ss) % mod;
		}
	}
	int dp[1005][4];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep(i, n) rep(x, 4) rep(y, 3) dp[i + 1][x ^ y] = (dp[i + 1][x ^ y] + 1LL * dp[i][x] * cnt[y]) % mod;
	int ans = 0;
	rep(x, 4) if (x) ans = (ans + dp[n][x]) % mod;
	printf("%d\n", ans);
	return 0;
}

inline void init() {
	rngs.push_back({1, 3, 0});
	rngs.push_back({3, 4, 1});
	rngs.push_back({4, 5, 2});
	rngs.push_back({5, 7, 1});
	rngs.push_back({7, 9, 2});
	rngs.push_back({9, 13, 0});
	rngs.push_back({13, 15, 1});
	rngs.push_back({15, 19, 2});
	rngs.push_back({19, 27, 0});
	rngs.push_back({27, 39, 1});
	rngs.push_back({39, 40, 2});
	rngs.push_back({40, 57, 0});
	rngs.push_back({57, 58, 2});
	rngs.push_back({58, 81, 1});
	rngs.push_back({81, 85, 2});
	rngs.push_back({85, 120, 0});
	rngs.push_back({120, 121, 2});
	rngs.push_back({121, 174, 1});
	rngs.push_back({174, 179, 2});
	rngs.push_back({179, 255, 0});
	rngs.push_back({255, 260, 2});
	rngs.push_back({260, 363, 1});
	rngs.push_back({363, 382, 2});
	rngs.push_back({382, 537, 0});
	rngs.push_back({537, 544, 2});
	rngs.push_back({544, 780, 1});
	rngs.push_back({780, 805, 2});
	rngs.push_back({805, 1146, 0});
	rngs.push_back({1146, 1169, 2});
	rngs.push_back({1169, 1632, 1});
	rngs.push_back({1632, 1718, 2});
	rngs.push_back({1718, 2415, 0});
	rngs.push_back({2415, 2447, 2});
	rngs.push_back({2447, 3507, 1});
	rngs.push_back({3507, 3622, 2});
	rngs.push_back({3622, 5154, 0});
	rngs.push_back({5154, 5260, 2});
	rngs.push_back({5260, 7341, 1});
	rngs.push_back({7341, 7730, 2});
	rngs.push_back({7730, 10866, 0});
	rngs.push_back({10866, 11011, 2});
	rngs.push_back({11011, 15780, 1});
	rngs.push_back({15780, 16298, 2});
	rngs.push_back({16298, 23190, 0});
	rngs.push_back({23190, 23669, 2});
	rngs.push_back({23669, 33033, 1});
	rngs.push_back({33033, 34784, 2});
	rngs.push_back({34784, 48894, 0});
	rngs.push_back({48894, 49549, 2});
	rngs.push_back({49549, 71007, 1});
	rngs.push_back({71007, 73340, 2});
	rngs.push_back({73340, 104352, 0});
	rngs.push_back({104352, 106510, 2});
	rngs.push_back({106510, 148647, 1});
	rngs.push_back({148647, 156527, 2});
	rngs.push_back({156527, 220020, 0});
	rngs.push_back({220020, 222970, 2});
	rngs.push_back({222970, 319530, 1});
	rngs.push_back({319530, 330029, 2});
	rngs.push_back({330029, 469581, 0});
	rngs.push_back({469581, 479294, 2});
	rngs.push_back({479294, 668910, 1});
	rngs.push_back({668910, 704371, 2});
	rngs.push_back({704371, 990087, 0});
	rngs.push_back({990087, 1003364, 2});
	rngs.push_back({1003364, 1437882, 1});
	rngs.push_back({1437882, 1485130, 2});
	rngs.push_back({1485130, 2113113, 0});
	rngs.push_back({2113113, 2156822, 2});
	rngs.push_back({2156822, 3010092, 1});
	rngs.push_back({3010092, 3169669, 2});
	rngs.push_back({3169669, 4455390, 0});
	rngs.push_back({4455390, 4515137, 2});
	rngs.push_back({4515137, 6470466, 1});
	rngs.push_back({6470466, 6683084, 2});
	rngs.push_back({6683084, 9509007, 0});
	rngs.push_back({9509007, 9705698, 2});
	rngs.push_back({9705698, 13545411, 1});
	rngs.push_back({13545411, 14263510, 2});
	rngs.push_back({14263510, 20049252, 0});
	rngs.push_back({20049252, 20318116, 2});
	rngs.push_back({20318116, 29117094, 1});
	rngs.push_back({29117094, 30073877, 2});
	rngs.push_back({30073877, 42790530, 0});
	rngs.push_back({42790530, 43675640, 2});
	rngs.push_back({43675640, 60954348, 1});
	rngs.push_back({60954348, 64185794, 2});
	rngs.push_back({64185794, 90221631, 0});
	rngs.push_back({90221631, 91431521, 2});
	rngs.push_back({91431521, 131026920, 1});
	rngs.push_back({131026920, 135332446, 2});
	rngs.push_back({135332446, 192557382, 0});
	rngs.push_back({192557382, 196540379, 2});
	rngs.push_back({196540379, 274294563, 1});
	rngs.push_back({274294563, 288836072, 2});
	rngs.push_back({288836072, 405997338, 0});
	rngs.push_back({405997338, 411441844, 2});
	rngs.push_back({411441844, 589621137, 1});
	rngs.push_back({589621137, 608996006, 2});
	rngs.push_back({608996006, 866508216, 0});
	rngs.push_back({866508216, 884431705, 2});
	rngs.push_back({884431705, 1000000007, 1});
}