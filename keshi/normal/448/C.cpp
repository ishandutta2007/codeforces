//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], dp[maxn][maxn], pd[maxn][maxn];

int main(){
	ll u, v;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= n && j <= a[i]; j++){
			dp[i][j] = pd[i - 1][min(j, a[i - 1])] + max(0, j - a[i - 1]) + (j != a[i]);
		}
		pd[i][min(n, a[i])] = dp[i][min(n, a[i])];
		for(ll j = min(n, a[i]) - 1; j > -1; j--){
			pd[i][j] = min(pd[i][j + 1], dp[i][j]);
		}
	}
	
	cout << pd[n][0];
	
	return 0;
}