//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e7 + 100;
const ll maxm = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull od(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
FastMod M(mod);

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ans;
int cnt[maxn], c[maxn], d[maxn], pd[maxn], a[maxm], p[maxm], dp[maxn], x;

int main(){
	fast_io;
	p[0] = 1;
	for(ll i = 1; i < maxm; i++){
		p[i] = p[i - 1] + p[i - 1];
		if(p[i] >= mod) p[i] -= mod;
	}
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	for(ll i = maxn - 1; i > 0; i--){
		c[i] = cnt[i];
		for(ll j = 2; i * j < maxn; j++){
			dp[i] -= dp[i * j];
			if(dp[i] < 0) dp[i] += mod;
			c[i] += cnt[i * j];
		}
		dp[i] += p[c[i]] - 1;
		if(dp[i] > mod) dp[i] -= mod;
	}
	d[1] = 1;
	for(ll i = 1; i < maxn; i++){
		x = c[i] * d[i];
		pd[i] += x;
		for(ll j = 2; i * j < maxn; j++){
			d[i * j] -= d[i];
			pd[i * j] += x;
		}
		if(i > 1) ans = M.od(ans + ll(dp[i]) * pd[i]);
	}
	
	cout << ans;
	
	return 0;
}