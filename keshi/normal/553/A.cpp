//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], ps[maxn], dp[maxn][maxn], pd[maxn][maxn], c[maxn][maxn];

int main(){
	fast_io;
	
	c[0][0] = 1;
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
	
	cin >> m;
	
	for(ll i = 1; i <= m; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	
	n = ps[m];
	
	for(ll i = 0; i <= n; i++){
		pd[0][i] = 1;
	}
	
	for(ll i = 1; i <= m; i++){
		for(ll j = ps[i]; j <= n; j++){
			dp[i][j] = (pd[i - 1][j - 1] * c[j - ps[i - 1] - 1][a[i] - 1]) % mod;
			pd[i][j] = (pd[i][j - 1] + dp[i][j]) % mod;
		}
	}
	
	cout << pd[m][n];
	
	return 0;
}