#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e6 + 10, mlg = 20, mod = 1e9 + 7;
int n, k, c[maxn][mlg], v[maxn][mlg], res[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> v[i][0], v[i][0]*=100;
	for(int i = 1; i <= n; i++) cin >> c[i][0];
	for(int j = 1; j < mlg; j++) {
		for(int i = 1; i + (1<<j)-1 <= n; i++) {
			v[i][j] = max(v[i][j-1], v[i+(1<<(j-1))][j-1]);
			c[i][j] = min(c[i][j-1], c[i+(1<<(j-1))][j-1]);
		}
	}
	ll sm = 0;
	for(int i = 1; i <= n; i++) {
		int ans = 0;
		for(int da = 1<<24; da>>=1;) {
			ans += da;

			int pos = i, maxv = 0;
			for(int dp = 20; dp--;) {
				if(pos+(1<<dp)-1<=n&&c[pos][dp]>=ans) {
					maxv = max(maxv, v[pos][dp]);
					pos += 1<<dp;
				}
			}

			if(maxv<ans) ans -= da;
		}
		res[i] = ans;
	}
	sort(res+1, res+n+1);
	reverse(res+1, res+n+1);
	ld ans = 0, t = (ld)k/(ld)n;
	for(int i = n; i >= k; i--) {
		ans += (ld)res[i]*t;
		t *= (ld)(i-k)/(ld)(i-1);
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}