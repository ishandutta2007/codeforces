#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dp[maxn][maxn], ps[maxn][26], cnt[26], ans;

string a, b;

int main(){
	fast_io;
	
	cin >> a >> b;
	
	n = a.size();
	m = b.size();
	
	a = ' ' + a;
	b = ' ' + b;
	
	for(ll j = 1; j <= m; j++){
		cnt[b[j] - 'a']++;
		for(ll i = 1; i <= n; i++){
			dp[i][j] = (ps[i - 1][a[i] - 'a'] + cnt[a[i] - 'a']) % mod;
			ps[i][b[j] - 'a'] = (ps[i][b[j] - 'a'] + dp[i][j - 1]) % mod;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		ans = (ans + dp[i][m]) % mod;
	}
	
	cout << ans;
	
	return 0;
}