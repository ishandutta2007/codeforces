//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 300;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, dp[maxn][maxn], p[maxn], p2[maxn], f[maxn], fp[maxn];

ll pw(ll a, ll b){
	if(b == 0) return 1;
	ll c = pw(a, b / 2);
	c = (c * c) % mod;
	if(b % 2) c = (c * a) % mod;
	return c;
}

ll C(ll a, ll b){
	if(b < 0 || b > a) return 0;
	return (((f[a] * fp[b]) % mod) * fp[a - b]) % mod;
}

int main(){
	fast_io;
	
	cin >> n >> k;
	
	p[0] = p2[0] = f[0] = fp[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = (p[i - 1] * k) % mod;
		p2[i] = (p2[i - 1] * (k - 1)) % mod;
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
	}
	
	dp[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= n; j++){
			for(ll o = 0; o <= j; o++){
				dp[i][j] += (((((C(j, o) * p2[n - j]) % mod) * p[o]) % mod) * dp[i - 1][o]) % mod;
				dp[i][j] %= mod;
			}
			dp[i][j] -= (dp[i - 1][j] * p2[n]) % mod;
			dp[i][j] %= mod;
		}
	}
	
	cout << (dp[n][n] + mod) % mod;
	
	return 0;
}