#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll inf = 1e18;

#define pb push_back
#define F first
#define S second

ll n, m, dp[maxn], s, t;

bool vis[maxn];

vector<ll> gin[maxn], gout[maxn];

set<pll> st[maxn];

priority_queue<pll> q;

int main(){
	ll v, u, c;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> n >> m;

	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		gout[v].pb(u);
		gin[u].pb(v);
	}

	cin >> s >> t;

	fill(dp, dp + n + 1, inf);

	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < gout[i].size(); j++){
			u = gout[i][j];
			st[i].insert({dp[u], u});
		}
	}

	q.push({0, t});

	while(!q.empty()){
		v = q.top().S;
		c = -q.top().F;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(ll i = 0; i < gin[v].size(); i++){
			u = gin[v][i];
			st[u].erase({dp[v], v});
		}
		dp[v] = c;
		for(ll i = 0; i < gin[v].size(); i++){
			u = gin[v][i];
			st[u].insert({dp[v], v});
			c = min(st[u].begin() -> F + 1, st[u].rbegin() -> F);
			q.push({-c, u});
		}
	}

	if(dp[s] >= inf) dp[s] = -1;

	cout << dp[s];

	return 0;
}