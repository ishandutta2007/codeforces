#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
const int ba = 10007;
const int mo = 18940417;
const int mo2 = 19491001;

int dp[N][32], n, m, x, pw[N], pw2[N], hs1[N], ht1[N], hs2[N], ht2[N];
char s[N], t[N];

int Hs1(int l, int r) { return (hs1[r] - 1ll * hs1[l - 1] * pw[r - l + 1] % mo + mo) % mo; }
int Ts1(int l, int r) { return (ht1[r] - 1ll * ht1[l - 1] * pw[r - l + 1] % mo + mo) % mo; }
int Hs2(int l, int r) { return (hs2[r] - 1ll * hs2[l - 1] * pw2[r - l + 1] % mo2 + mo2) % mo2; }
int Ts2(int l, int r) { return (ht2[r] - 1ll * ht2[l - 1] * pw2[r - l + 1] % mo2 + mo2) % mo2; }
int lcp(int sl, int tl) {
	if(s[sl] != t[tl]) return 0;
	int l = 1, r = min(n - sl + 1, m - tl + 1), ans = 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(Hs1(sl, sl + mid - 1) == Ts1(tl, tl + mid - 1) && Hs2(sl, sl + mid - 1) == Ts2(tl, tl + mid - 1)) l = (ans = mid) + 1;
		else r = mid - 1;
	}
	return ans;
}
int main() {
	for(int i = pw[0] = 1; i < N; i ++)
		pw[i] = 1ll * pw[i - 1] * ba % mo;
	for(int i = pw2[0] = 1; i < N; i ++)
		pw2[i] = 1ll * pw2[i - 1] * ba % mo2;
	scanf("%d%s%d%s%d", &n, s + 1, &m, t + 1, &x);
	for(int i = 1; i <= n; i ++) hs1[i] = (1ll * hs1[i - 1] * ba + s[i]) % mo;
	for(int i = 1; i <= m; i ++) ht1[i] = (1ll * ht1[i - 1] * ba + t[i]) % mo;
	for(int i = 1; i <= n; i ++) hs2[i] = (1ll * hs2[i - 1] * ba + s[i]) % mo2;
	for(int i = 1; i <= m; i ++) ht2[i] = (1ll * ht2[i - 1] * ba + t[i]) % mo2;
	dp[0][0] = 0;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j <= x; j ++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if(j < x) {
				int y = lcp(i + 1, dp[i][j] + 1);
				if(y) dp[i + y][j + 1] = max(dp[i + y][j + 1], dp[i][j] + y);
			}
		}
	}
	bool ans = 0;
	for(int i = 0; i <= x; i ++)
		if(dp[n][i] == m) ans = 1, i = x;
	puts(ans ? "YES" : "NO");
	return 0;
}