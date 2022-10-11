#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dp[MAXN], ans;

pair<ll, pll> e[MAXN];

vector<pll> upd;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> e[i].S.F >> e[i].S.S >> e[i].F;
	}
	
	sort(e, e + m);
	
	for(ll i = 0; i < m; i++){
		upd.clear();
		upd.pb({e[i].S.S, dp[e[i].S.F] + 1});
		while(i + 1 < m && e[i].F == e[i + 1].F){
			i++;
			upd.pb({e[i].S.S, dp[e[i].S.F] + 1});
		}
		for(ll j = 0; j < upd.size(); j++){
			ans = max(ans, upd[j].S);
			dp[upd[j].F] = max(dp[upd[j].F], upd[j].S);
		}
	}
	
	cout << ans;
	
	return 0;
}