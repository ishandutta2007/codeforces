#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)
 
inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int dp[100005];
int n;
int a[100005];
vi ans[100005];
bool use[100005];
int prv[100005];
vi tmp[100005];

void Main() {
	n = read();
	rep(i, n) a[i] = read();
	rep(i, n + 1) use[i] = 0;
	int k = 0;
	int nn = n;
	while (nn) {
		rep(i, n + 1) dp[i] = inf;
		rep(i, n) if (!use[a[i]]) {
			int ps = lower_bound(dp + 1, dp + n + 1, a[i]) - dp;
			dp[ps] = a[i];
			prv[a[i]] = dp[ps - 1];
		}
		int i = 0;
		while (i + 1 <= n && dp[i + 1] < inf) ++ i;
		if (i * (i + 1) / 2 <= nn) {
			rep(i, n + 1) dp[i] = inf;
			rep(i, n + 1) tmp[i].clear();
			rep(i, n) if (!use[a[i]]) {
				int ps = lower_bound(dp + 1, dp + n + 1, a[i]) - dp;
				dp[ps] = a[i];
				tmp[ps].pb(a[i]);
				-- nn;
			}
			rep(i, n + 1) if (!tmp[i].empty()) ans[k ++] = tmp[i];
		} else {
			i = dp[i];
			ans[k].clear();
			while (i != inf) {
				ans[k].pb(i);
				use[i] = 1;
				i = prv[i];
				-- nn;
			}
			reverse(ans[k].begin(), ans[k].end());
			++ k;
		}
	}
	printf("%d\n", k);
	rep(i, k) {
		printf("%d", (int) ans[i].size());
		rep(j, ans[i].size()) printf(" %d", ans[i][j]);
		printf("\n");
	}
}

int main() {
	// freopen("dat.in", "r", stdin);
	int T = read(); while (T --) Main();
	return 0;
}