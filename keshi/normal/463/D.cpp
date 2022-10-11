#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[10][MAXN], b[10][MAXN], dp[MAXN];
bool f;

vector<ll> g[MAXN];

ll dfs(ll v){
	if(dp[v]){
		return dp[v];
	}
	for(ll i = 0; i < g[v].size(); i++){
		dp[v] = max(dp[v], dfs(g[v][i]));
	}
	dp[v]++;
	return dp[v];
}

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < k; i++){
		for(ll j = 0; j < n; j++){
			cin >> a[i][j];
			b[i][a[i][j]] = j;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			f = 1;
			for(ll d = 0; d < k; d++){
				if(b[d][i] >= b[d][j]){
					f = 0;
				}
			}
			if(f){
				g[j].pb(i);
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(dp[i] == 0){
			dp[i] = dfs(i);
		}
	}
	
	cout << *max_element(dp + 1, dp + n + 1);
	
	return 0;
}