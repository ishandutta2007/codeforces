//In the name of GOD
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

ll n, m, k, a[maxn], ps[maxn], dp[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	
	for(ll i = m; i <= n; i++){
		for(ll j = 1; j <= k; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + ps[i] - ps[i - m]);
		}
	}
	
	cout << dp[n][k];
	
	return 0;
}