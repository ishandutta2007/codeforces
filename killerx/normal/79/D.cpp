#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 10005;

int n, K, L;
int a[105];
bool hav[mxn];

int main() {
	scanf("%d %d %d", &n, &K, &L);
	rep(i, K) {
		int x; scanf("%d", &x);
		-- x;
		hav[x] ^= 1;
		hav[x + 1] ^= 1;
	}
	rep(i, L) scanf("%d", &a[i]);
	std::vector <int> vec;
	rep(i, n + 1) if (hav[i]) vec.push_back(i);
	static int ans[25][25];
	rep(_, vec.size()) {
		int S = vec[_];
		static int dis[mxn];
		std::priority_queue <std::pair <int, int> > pq;
		memset(dis, 0x3f, sizeof(dis));
		dis[S] = 0;
		pq.push({-dis[S], S});
		while (!pq.empty()) {
			int p = pq.top().second;
			int d = -pq.top().first;
			pq.pop();
			if (d != dis[p]) continue;
			rep(i, L) {
				int l = a[i];
				if (p - l >= 0) {
					if (dis[p - l] > dis[p] + 1) {
						dis[p - l] = dis[p] + 1;
						pq.push({-dis[p - l], p - l});
					}
				}
				if (p + l <= n) {
					if (dis[p + l] > dis[p] + 1) {
						dis[p + l] = dis[p] + 1;
						pq.push({-dis[p + l], p + l});
					}
				}
			}
		}
		rep(__, vec.size()) ans[_][__] = dis[vec[__]];
	}
	static int dp[1 << 20];
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	rep(mask, 1 << vec.size()) if (mask) {
		int u = __builtin_ctz(mask);
		rep(v, vec.size()) if (u != v && (mask >> v & 1)) {
			dp[mask] = std::min(dp[mask], dp[mask ^ 1 << u ^ 1 << v] + ans[u][v]);
		}
	}
	int res = dp[(1 << vec.size()) - 1];
	if (res > 1e9) puts("-1");
	else printf("%d\n", res);
	return 0;
}