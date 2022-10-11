//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 30;
const ll maxm = 1e7 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], k, x, y, ans, b, c, f[maxn][maxn];

vector<pll> g[maxn];

bitset<maxm> dp;

int main(){
	fast_io;
	
	cin >> n;
	
	if(n == 1){
		cout << 1;
		return 0;
	}
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = i; j < n; j++){
			for(ll o = j + 1; o < n; o++){
				if(a[o] == a[i] + a[j]) g[o].pb({i, j}), f[o][j] = i + 1, f[o][i] = j + 1;
			}
		}
	}
	
	dp[1] = 1;
	ans = inf;
	
	for(ll i = 2; i < (1ll << n); i++){
		k = (31 - __builtin_clz(i));
		bool p = 0;
		for(ll j = 0; j < g[k].size(); j++){
			b = g[k][j].F;
			c = g[k][j].S;
			if((i >> b) & (i >> c) & 1) p = 1;
		}
		if(p){
			for(ll j = 0; j < k; j++){
				y = (i - (1ll << k)) | (1ll << j);
				if((y >> (k - 1)) & 1 && dp[y]) dp[i] = 1;
			}
		}
		else{
			for(ll j = 0; j < k; j++){
				y = (i - (1ll << k)) | (1ll << j);
				if(f[k][j] != 0 && (y >> (f[k][j] - 1)) & (y >> (k - 1)) & 1 && dp[y]) dp[i] = 1;
			}
		}
		if(k == n - 1 && dp[i]) ans = min(ans, __builtin_popcount(i));
	}
	if(ans == inf) ans = -1;
	
	cout << ans;
	
	return 0;
}