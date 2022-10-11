//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll k, aa, bb, a, b, ans, p, bp, bx, x, y, dp[maxn][maxn], t[maxn];

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	
	cin >> k >> aa >> bb;
	
	a = (aa * pw(aa + bb, mod - 2)) % mod;
	b = (bb * pw(aa + bb, mod - 2)) % mod;
	bp = pw(b, mod - 2);
	bx = (bp* a) % mod;
	t[0] = 1;
	for(ll i = 1; i < maxn; i++){
	    t[i] = (t[i - 1] * a) % mod;
	}
	
	dp[0][0] = 1;
	x = 1;
	
	for(ll i = 0; i < k; i++){
		for(ll j = 0; j < k; j++){
			p = (dp[i][j] * b) % mod;
			y = 0;
			for(; i + j + x < k; x++){
				dp[i + j + x][j + x] = (dp[i + j + x][j + x] + p * t[y]) % mod;
				y++;
			}
			ans = (ans + ((t[y] * dp[i][j]) % mod) * (bx + i + j + x)) % mod;
			x = 0;
		}
	}
	
	cout << ans;
	
	return 0;
}