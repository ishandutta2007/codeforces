//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 350;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, x, b[maxn], f[maxn], fp[maxn], inv[maxn], dp[maxn][maxn], ans, dp2[maxn][maxn];
map<ll, ll> c;

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb & 1) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	f[0] = fp[0] = 1;
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
		inv[i] = pw(i, mod - 2);
	}
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a;
		x = 1;
		for(ll j = 2; j * j <= a; j++){
			if(a % j == 0){
				while(a % (j * j) == 0) a /= j * j;
				if(a % j == 0) a /= j, x *= j;
			}
		}
		x *= a;
		c[x]++;
	}
	x = 1;
	for(map<ll, ll>::iterator it = c.begin(); it != c.end(); it++){
		b[x++] = it -> S;
	}
	dp2[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= i; j++){
			for(ll k = 1; k <= i; k++){
				dp2[i][j] = (dp2[i][j] + ((((dp2[i - k][j - 1] * k) % mod) * f[i - 1]) % mod) * fp[i - k]) % mod;
			}
		}
	}
	dp[0][0] = 1;
	for(ll i = 1; i < x; i++){
		for(ll j = 0; j <= n; j++){
			for(ll k = 1; k <= b[i]; k++){
				if(j < k) continue;
				dp[i][j] = (dp[i][j] + (dp[i - 1][j - k] * dp2[b[i]][k]) % mod) % mod;
			}
		}
	}
	for(ll i = 0; i <= n; i++){
		if(i % 2 == n % 2) ans = (ans + dp[x - 1][i] * f[i]) % mod;
		else ans = (ans - dp[x - 1][i] * f[i]) % mod;
	}
	cout << (ans + mod) % mod;
	
	return 0;
}