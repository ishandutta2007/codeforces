#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll C=36,full = (1ll<<C)-1;
#define get(x, y) (((x)>>(y))&1)
ll shuffle(ll a, ll msk) {
	ll y = 1,  x = 1ll<<__builtin_popcountll(msk), r = 0;
	for(int i = 0; i < C; i++) {
		if(get(msk, i)) swap(x, y);
		r |= get(a, i)*x;
		x<<=1;
		if(get(msk, i)) swap(x, y);
	}
	return r;
}
ll n, m, basis[60], ans[60], sz;
vi hv;
void add(ll x) {
	for(int i = C; i--;) {
		if(!((x>>i)&1)) continue;
		if(basis[i]) x ^= basis[i];
		else {
			basis[i] = x;break;
		}
	}
}
ll good = 0;
void post() {
	for(int i = 0; i < C; i++) {
		if(!basis[i]) {
			good|=1ll<<i;
			continue;
		}
		for(int j = i; j--;) {
			if(!basis[j]) continue;
			basis[i] = min(basis[i], basis[i]^basis[j]);
		}
		hv.pb(basis[i]);
	}
}
int dp[1<<18][54];
void solve() {
	dp[0][0] = 1;
	int cur = 0;
	ll mx = (1ll<<sz)-1;
	for(int i = 0; i < C; i++) {
		if(!basis[i]) continue;
		ll x = shuffle(basis[i], good);
		x &= mx;
		for(int cnt = 53; cnt--;) {
			for(int j = 0; j <= mx; j++) {
				dp[j^x][cnt+1] += dp[j][cnt];
				if(dp[j^x][cnt+1]>=mod) dp[j^x][cnt+1] -= mod;
			}
		}
	}
	for(int cnt = 54; cnt--;) {
		for(int j = 0; j <= mx; j++) {
			int t = cnt + __builtin_popcount(j);
			ans[t] += dp[j][cnt];
			if(ans[t]>=mod) ans[t] -= mod;
		}
	}
	ll q= 1;
	for(int i = hv.size(); i < n; i++) q = q*2ll%mod;
	for(int i = 0; i <= m; i++) cout << ans[i]*q%mod << " ";
}
ll a[1<<15], b[1<<15];
void baka() {
	int x = min((ll)hv.size(), 15ll);
	int y = max(0ll, (ll)hv.size()-15);
	for(int i = 0; i < 1<<x; i++) {
		for(int j = 0; j < x; j++)
			if((i>>j)&1) a[i] ^= hv[j];
	}
	for(int i = 0; i < 1<<y; i++) {
		for(int j = 0; j < y; j++)
			if((i>>j)&1) b[i] ^= hv[15+j];
	}
	#pragma GCC ivdep
	for(int i = 1<<hv.size(); i--;) {
		++ans[__builtin_popcountll(a[i&((1<<15)-1)]^b[i>>15])];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll t, i = 1; i <= n; i++) {
		cin >> t;
		add(t);
	}
	post();
	sz = __builtin_popcountll(good);
	if(sz<6) {
		solve();
	} else {
		baka();
		ll q = 1;
		for(int i = hv.size(); i < n; i++) q = q*2ll%mod;
		for(int i = 0; i <= m; i++) cout << ans[i]*q%mod << " ";
	}
	return 0;
}