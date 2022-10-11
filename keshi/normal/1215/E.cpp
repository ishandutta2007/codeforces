//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 20;
const ll maxm = 11e5;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, t, x, a[maxm], b[maxn], c[maxn], d[maxn][maxn], dp[maxm];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		c[a[i]]++;
		for(ll j = 0; j < 20; j++){
			d[a[i]][j] += c[j];
		}
	}
	
	for(ll i = 0; i < 20; i++){
		d[i][i] = 0;
	}
	
	for(ll i = 1; i < (1ll << maxn); i++){
		t = __builtin_popcount(i);
		x = i;
		for(ll j = 0; j < t; j++){
			b[j] = __builtin_ctz(x);
			x -= (1ll << b[j]);
		}
		dp[i] = inf;
		for(ll j = 0; j < t; j++){
			x = 0;
			for(ll k = 0; k < t; k++){
				x += d[b[k]][b[j]];
			}
			dp[i] = min(dp[i], dp[i - (1ll << b[j])] + x);
		}
	}
	
	cout << dp[(1ll << maxn) - 1];
	
	return 0;
}