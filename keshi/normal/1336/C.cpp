//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, dp[maxn][maxn], r, ans;

string s, t;

int main(){
	fast_io;
	
	cin >> s >> t;
	
	n = s.size();
	m = t.size();
	
	for(ll i = 0; i <= n; i++){
		dp[i][i] = 1;
	}
	
	for(ll i = 0; i < n; i++){
		for(ll l = 0; l + i < n; l++){
			r = l + i + 1;
			if(r - 1 >= m || s[i] == t[r - 1]) dp[l][r] += dp[l][r - 1];
			if(l >= m || s[i] == t[l]) dp[l][r] += dp[l + 1][r];
			if(l == 0 && r >= m) ans = (ans + dp[l][r]) % mod;
			dp[l][r] %= mod;
		}
	}
	
	cout << ans;
	
	return 0;
}