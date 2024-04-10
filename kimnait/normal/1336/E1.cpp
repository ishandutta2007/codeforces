#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP  make_pair
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = 998244353;
const int N = (int)1e6 + 7;
long long a[ N ], bs[37], st[37], st2[37];
long long b[37];
int ans[37];
long long mypow(long long v, long long t) {
	long long res = 1;
	while (t) {
		if (t & 1) res = res*v%mod;
		t >>= 1;
		v = v*v%mod;
	}
	return res;
}
void dfs(int dep, long long val) {
	if (dep == -1) {
		ans[__builtin_popcountll(val)]++;
		return ;
	}
	dfs(dep-1, val ^ st[dep]);
	dfs(dep-1, val);
}
long long add(long long v1, long long v2) {
	v1 += v2; if (v1 >= mod) v1 -= mod;
	return v1;
}
long long dp[37][10000];
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%lld", a + i);

	int k = 0;
	long long mk = 0;
	for (int i = 1; i <= n; i++) {
		long long v = a[i];
		for (int j = m - 1; j >= 0; j--) {
			if (bs[j]) {
				v = min(v, v ^ bs[j]);
			} else if (v & (1ll<<j)){
				bs[j] = v;
				st[k] = v;
				st2[k] = 1ll<<j;
				mk ^= 1ll<<j;
				k++;
				break ;
			}
		}
	}
	if (k <= 22) {
		dfs(k-1, 0);
	} else {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i == j) continue ;
				if (st2[i] & st[j]) {
					st[j] ^= st[i];
				}
			}
		}
		for (int i = 0; i < k; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (mk & (1ll<<j)) continue ;
				if (st[i] & (1ll<<j)) b[i] |= 1ll<<cnt;
				cnt++;
			}
		}

		dp[0][0] = 1;
		int kk = 1ll<<(m - k);
		for (int i = 0; i < k; i++) {
			for (int j = i; j >= 0; j--) {
				for (int mask = 0; mask < kk; mask++) {
					dp[j+1][mask ^ b[i]] = add(dp[j+1][mask ^ b[i]], dp[j][mask]);
				}
			}
		}
		for (int mask = 0; mask < kk; mask++) {
			int num = __builtin_popcount(mask);
			for (int i = 0; i <= k; i++) {
				ans[num + i] = add(ans[num + i], dp[i][mask]);
			}
		}
	}
	long long bs = mypow(2, n - k);
	for (int i = 0; i <= m; i++)
		ans[i] = ans[i]*bs%mod;
	for (int i = 0; i <= m; i++)
		printf("%d%c", ans[i], " \n"[i == m]);
	return 0;
}