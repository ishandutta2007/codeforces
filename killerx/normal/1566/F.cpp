#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 20;

int np, nr;
std::vector <int> vec;
int a[mxn];
std::pair <int, int> rng[mxn];

void Main() {
	scanf("%d %d", &np, &nr);
	vec.clear();
	rep(i, np) scanf("%d", &a[i]);
	std::set <int> A;
	rep(i, np) A.insert(a[i]);
	rep(i, nr) scanf("%d %d", &rng[i].first, &rng[i].second);
	rep(i, nr) rng[i].second *= -1;
	std::set <std::pair <int, int> > st;
	rep(i, np) st.insert({a[i], -a[i]});
	std::sort(rng, rng + nr);
	std::reverse(rng, rng + nr);
	rep(i, nr) {
		auto pr = rng[i];
		auto it = st.lower_bound(pr);
		if (it != st.end() && it->second >= rng[i].second) continue;
		st.insert(pr);
	}
	nr = 0;
	for (auto pr : st) {
		rng[nr] = pr;
		rng[nr].second *= -1;
		++ nr;
	}
	// rep(i, nr) eprintf("[%d, %d]\n", rng[i].first, rng[i].second);
	// eprintf("\n");
	static long long dp[mxn][7];
	rep(i, nr + 1) rep(j, 7) dp[i][j] = 1LL << 60;
	dp[0][0] = 0;
	rep(i, nr) {
		rep(state, 7) {
			if (rng[i].first == rng[i].second && A.find(rng[i].first) != A.end()) {
				dp[i + 1][state] = std::min(dp[i + 1][state], dp[i][state]);
				if (state == 0) dp[i + 1][1] = std::min(dp[i + 1][1], dp[i][state] - rng[i].first);
				if (state == 2) dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][state] + rng[i].first);
				if (state == 3) dp[i + 1][4] = std::min(dp[i + 1][4], dp[i][state] + rng[i].first);
				if (state == 5) dp[i + 1][6] = std::min(dp[i + 1][6], dp[i][state] - rng[i].first);
			} else {
				if (state) dp[i + 1][state] = std::min(dp[i + 1][state], dp[i][state]);
				if (state == 0) {
					dp[i + 1][2] = std::min(dp[i + 1][2], dp[i][state] - rng[i].second);
					dp[i + 1][3] = std::min(dp[i + 1][3], dp[i][state] - 2 * rng[i].second);
					dp[i + 1][5] = std::min(dp[i + 1][5], dp[i][state] - rng[i].second);
				}
				if (state == 1) dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][state] + rng[i].first);
				if (state == 4) dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][state] + rng[i].first);
				if (state == 6) dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][state] + 2 * rng[i].first);
			}
		}
	}
	printf("%lld\n", dp[nr][0]);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}