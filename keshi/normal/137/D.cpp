//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, ans, dp[maxn][maxn], cost[maxn][maxn], par[maxn][maxn], t, r;

bool vis[maxn];

vector<ll> v;

string s;

int main(){
	fast_io;
	
	cin >> s >> k;
	
	n = s.size();
	
	for(ll d = 1; d < n; d++){
		for(ll l = 0; l + d < n; l++){
			ll r = l + d;
			cost[l][r] = cost[l + 1][r - 1] + (s[l] != s[r]);
		}
	}
	
	for(ll i = 0; i < n; i++){
		dp[i][1] = cost[0][i];
		par[i][1] = -1ll;
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 2; j <= k; j++){
			dp[i][j] = inf;
			for(ll k = 0; k < i; k++){
				if(dp[i][j] > dp[k][j - 1] + cost[k + 1][i]){
					dp[i][j] = dp[k][j - 1] + cost[k + 1][i];
					par[i][j] = k;
				}
			}
		}
	}
	
	ans = inf;
	for(ll i = 1; i <= k; i++){
		if(ans > dp[n - 1][i]){
			ans = dp[n - 1][i];
			t = i;
		}
	}
	r = n - 1;
	while(r >= 0){
		v.pb(r);
		r = par[r][t--];
		vis[r] = 1;
	}
	v.pb(-1ll);
	for(ll i = 0; i + 1 < v.size(); i++){
		ll k = v[i + 1] + 1;
		for(ll j = v[i]; j > k; j--, k++){
			s[j] = s[k];
		}
	}
	
	
	cout << ans << endl;
	
	for(ll i = 0; i < n; i++){
		cout << s[i];
		if(vis[i]){
			cout << '+';
		}
	}
	
	return 0;
}