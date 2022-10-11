//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e3 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, k, dp[maxn], ans, s, C[maxn][maxn];

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = pc * pc % mod;
	if(pb & 1) pc = pc * pa % mod;
	return pc;
}

int main(){
	fast_io;
	
	C[0][0] = 1;
	for(ll i = 1; i < maxn; i++){
		C[i][0] = 1;
		for(ll j = 1; j < maxn; j++){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if(C[i][j] >= mod) C[i][j] -= mod;
		}
	}
	
	cin >> n >> m >> k;
	
	s = 1;
	for(ll i = 1; i <= k; i++){
		s = s * (n - i + 1) % mod * pw(i * m % mod, mod - 2) % mod;
		dp[i] = pw(i, k);
		for(ll j = 1; j < i; j++){
			dp[i] = (dp[i] - C[i][j] * dp[j]) % mod;
		}
		ans = (ans + s * dp[i]) % mod;
	}
	cout << (ans + mod) % mod;
	
	return 0;
}