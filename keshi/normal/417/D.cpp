//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll maxm = 11e5;
const ll mod = 1e9 + 7;
const ll inf = 8e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, b, k, x, dp[2][maxm], ans;

pair<ll, pll> a[maxn];

int main(){
	fast_io;
	
	cin >> n >> m >> b;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].S.S >> a[i].F >> k;
		for(ll j = 0; j < k; j++){
			cin >> x;
			a[i].S.F += (1ll << (x - 1));
		}
	}
	
	sort(a + 1, a + n + 1);
	
	fill(dp[0] + 1, dp[0] + maxm, inf);
	ans = inf;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < (1ll << m); j++){
			dp[i % 2][j] = min(dp[1 - i % 2][j], dp[1 - i % 2][j & (~a[i].S.F)] + a[i].S.S);
		}
		ans = min(ans, a[i].F * b + dp[i % 2][(1ll << m) - 1]);
	}
	
	if(ans == inf) ans = -1;
	cout << ans;
	
	return 0;
}