#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 44;
int n, k, ans, dp[1 << 21];
ll a[N];
inline bool inc(ll s, ll s0) {
	return (s & s0) == s0;
}
int main() {
	scanf("%d%d", &n, &k);
	for(int x, i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			scanf("%d", &x);
			if(x) a[i] ^= 1ll << j;
		}
	}
	if(n == 1) return puts("0"), 0;
	ans = 1; dp[0] = 0;
	for(int i = 1; i < (1 << (n >> 1)); i ++) {
		bool tag = 1; int cnt = 0;
		for(int j = 0; j < (n >> 1); j ++) {
			if(i >> j & 1) {
				cnt ++;
				if(!inc(a[j], i ^ (1 << j))) {
					tag = 0;
				}
				dp[i] = max(dp[i], dp[i ^ (1 << j)]);
			}
		}
		if(tag) {
			dp[i] = cnt;
		}
	}
	for(int i = 0; i < (1 << (n - (n >> 1))); i ++) {
		bool tag = 1; int cnt = 0, S = (1 << (n >> 1)) - 1;
		for(int j = 0; j < (n - (n >> 1)); j ++) {
			if(i >> j & 1) {
				cnt ++;
				if(!inc(a[(n >> 1) + j], (i ^ (1ll << j)) << (n >> 1))) {
					tag = 0; break ;
				}
				S &= a[(n >> 1) + j];
			}
		}
		if(tag) {
			ans = max(ans, cnt + dp[S]);
		}
	}
	printf("%.8f\n", k * k * (ans - 1) * 1.0 / (ans * 2));
	return 0;
}