//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1100;
const ll maxm = 50;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, k, dp[maxm][maxn][2], ps[maxm][maxn][2], f[maxn], c[maxn][maxn], ans[maxn][maxm];

int main(){
	fast_io;
	
	f[0] = 1;
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
	}
	
	c[0][0] = 1;
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	
	dp[0][0][0] = 1;
	ps[0][0][0] = 1;
	ps[0][0][1] = 1;
	
	for(ll x = 1; x < maxn; x++){
		for(ll i = 1; i < maxm; i++){
			for(ll j = 0; j < maxn; j++){
				dp[i][j][x % 2] = 0;
				if(j - x + 1 >= 0) dp[i][j][x % 2] = ps[i - 1][j - x + 1][1 - x % 2];
				ps[i][j][x % 2] = (ps[i][j][1 - x % 2] + dp[i][j][x % 2]) % mod;
			}
		}
	}
	
	cin >> t;
	
	while(t--){
		cin >> n >> k;
		if((k - 1) * (k + 2) / 2 >= n){
			cout << "0\n";
			continue;
		}
		if(ans[n][k] == 0){
			for(ll x = 0; x <= n; x++){
				ans[n][k] = (ans[n][k] + (ps[k][x][1 - x % 2] * c[n - x][k]) % mod) % mod;
			}
			ans[n][k] = (ans[n][k] * f[k]) % mod;
		}
		cout << ans[n][k] << '\n';
	}
	
	return 0;
}