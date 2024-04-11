#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
using state = array<int, 2>;
state dp[32][2][2][2];
state inc(state a, int b) {
	return {a[0], (a[1] + a[0]*1ll*b)%mod};	
}
void add(array<int, 2> &a, array<int, 2> b) {
	a[0] += b[0], a[1] += b[1];
	if(a[0] >= mod) a[0] -= mod;
	if(a[1] >= mod) a[1] -= mod;
}
int f(int x, int y, int k) {
	memset(dp, 0, sizeof dp);
	dp[0][0][0][0] = {1, 0};
	for(int i = 0; i < 31; i++) {
		int ca = (x>>i)&1, cb = (y>>i)&1, cc = (k>>i)&1;
		for(int ra = 0; ra < 2; ra++)
			for(int rb = 0; rb < 2; rb++)
				for(int rc = 0; rc < 2; rc++)
					for(int na = 0; na < 2; na++)
						for(int nb = 0; nb < 2; nb++) {
							int nra = (ca == na      ? ra : na      < ca);
							int nrb = (cb == nb      ? rb : nb      < cb);
							int nrc = (cc == (na^nb) ? rc : (na^nb) < cc);
							add(dp[i+1][nra][nrb][nrc],
							(na^nb) ? inc(dp[i][ra][rb][rc], 1<<i) : dp[i][ra][rb][rc]
							);
						}
	}
	auto t = dp[31][1][1][1];
	return (t[0] + t[1])%mod;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, xl, xr, yl, yr, k;
	cin >> t;
	while(t--) {
		cin >> xl >> yl >> xr >> yr >> k;--xl, --yl;
		cout << (mod*4ll + f(xr, yr, k) - f(xl, yr, k) - f(xr, yl, k) + f(xl, yl, k))%mod << '\n';
	}
	
}