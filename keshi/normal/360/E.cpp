//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()


ll n, m, k, s1, s2, f, d[3][maxn], c[maxn][2];
pll b[maxn], par[maxn];
vector<pll> g[2][maxn];
bool vis[maxn], ok[maxn];

void solve(ll id, ll s, ll j, ll j2){
	priority_queue<pll> q;
	fill(vis, vis + n + 1, 0);
	fill(d[id], d[id] + n + 1, inf);
	d[id][s] = 0;
	q.push(Mp(-d[id][s], s));
	while(!q.empty()){
		ll v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(pll u : g[j][v]){
			if(ok[u.S] && d[id][u.F] > d[id][v] + c[u.S][j2]){
				d[id][u.F] = d[id][v] + c[u.S][j2];
				q.push(Mp(-d[id][u.F], u.F));
				par[u.F] = Mp(v, u.S);
			}
		}
	}
	return;
}

void dfs(ll v){
	vis[v] = 1;
	for(pll j : g[1][v]){
		if(ok[j.S] && !vis[j.F]){
			par[j.F] = Mp(v, j.S);
			dfs(j.F);
		}
	}
	return;
}

int main(){
    fast_io;

	cin >> n >> m >> k;
	cin >> s1 >> s2 >> f;
	for(ll i = 0; i < m; i++){
		ll v, u, l;
		cin >> v >> u >> l;
		c[i][0] = l;
		c[i][1] = l;
		g[0][v].pb(Mp(u, i));
		g[1][u].pb(Mp(v, i));
	}
	for(ll i = m; i < m + k; i++){
		ll v, u, l, r;
		cin >> v >> u >> l >> r;
		c[i][0] = l;
		c[i][1] = r;
		g[0][v].pb(Mp(u, i));
		g[1][u].pb(Mp(v, i));
	}
	fill(ok, ok + m + k, 1);
	solve(1, s1, 0, 0);
	solve(2, s2, 0, 1);
	for(ll i = 1; i <= n; i++){
		for(pll j : g[1][i]){
			ll y = d[1][j.F] + c[j.S][0];
			b[j.S] = Mp(y, d[2][i]);
		}
	}
	for(ll i = 0; i < m + k; i++){
		ok[i] = (b[i].F < b[i].S);
	}
	solve(0, f, 1, 0);
	if(d[0][s1] == d[1][f] && s1 != s2){
		cout << "WIN\n";
		ll v = s1;
		while(v != f){
			c[par[v].S][1] = c[par[v].S][0];
			v = par[v].F;
		}
		for(ll i = m; i < m + k; i++){
			cout << c[i][1] << " ";
		}
		return 0;
	}
	for(ll i = 0; i < m + k; i++){
		ok[i] = (b[i].F <= b[i].S);
	}
	solve(0, f, 1, 0);
	if(d[0][s1] == d[1][f]){
		cout << "DRAW\n";
		ll v = s1;
		while(v != f){
			c[par[v].S][1] = c[par[v].S][0];
			v = par[v].F;
		}
		for(ll i = m; i < m + k; i++){
			cout << c[i][1] << " ";
		}

		return 0;
	}
	cout << "LOSE\n";

    return 0;
}