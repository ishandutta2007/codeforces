//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll h, w, n, dp[maxn], f[maxn], fp[maxn];

pll p[maxn];

ll pw(ll a, ll b){
	if(b == 0) return 1;
	ll c = pw(a, b / 2);
	c = (c * c) % mod;
	if(b % 2) c = (a * c) % mod;
	return c;
}

ll c(ll a, ll b){
	return (((f[a + b ] * fp[a]) % mod) * fp[b]) % mod;
}

int main(){
	fast_io;
	
	f[0] = 1;
	fp[0] = pw(f[0], mod - 2);
	
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
	}
	
	cin >> h >> w >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> p[i].F >> p[i].S;
	}
	
	p[n] = make_pair(h, w);
	
	sort(p, p + n + 1);
	
	for(ll i = 0; i <= n; i++){
		dp[i] = c(p[i].F - 1, p[i].S - 1);
		for(ll j = 0; j < i; j++){
			if(p[i].F >= p[j].F && p[i].S >= p[j].S){
				dp[i] = (dp[i] - dp[j] * c(p[i].F - p[j].F, p[i].S - p[j].S)) % mod;
			}
		}
	}
	
	cout << (dp[n] + mod) % mod;
	
	return 0;
}