//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e3 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, l, dp[2 * maxn][maxn], s[2 * maxn][maxn];

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	
	cin >> n >> k >> l;
	dp[0][0] = 1;
	for(ll i = 1; i <= 2 * n; i++){
		for(ll j = 0; j + 1 < maxn; j++){
			if(j) dp[i][j] = dp[i - 1][j - 1], s[i][j] = s[i - 1][j - 1];
			dp[i][j] = (dp[i][j] + dp[i - 1][j + 1] * (j + 1)) % mod;
			s[i][j] = (s[i][j] + s[i - 1][j + 1] * (j + 1)) % mod;
			if(j >= k) s[i][j] = (s[i][j] + dp[i][j]) % mod;
		}
	}
	cout << (((((s[2 * n][0] * pw(dp[2 * n][0], mod - 2)) % mod)* l) % mod) * pw(2 * n + 1, mod - 2)) % mod;
	
	return 0;
}