//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, p, dp[maxn], par[maxn], ans[maxn], x, t;

pll a[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	
	sort(a + 1, a + n + 1);
	
	m = inf;
	dp[0] = -a[1].F;
	dp[1] = inf;
	dp[2] = inf;
	
	for(ll i = 3; i <= n; i++){
		if(dp[i - 3] < m){
			m = dp[i - 3];
			p = i - 3;
		}
		dp[i] = m + a[i].F - a[i + 1].F;
		par[i] = p;
	}
	
	x = n;
	t = 1;
	
	while(x > 0){
		for(ll j = x; j > par[x]; j--){
			ans[a[j].S] = t;
		}
		x = par[x];
		t++;
	}
	
	cout << dp[n] << " " << t - 1 << endl;
	
	for(ll i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}