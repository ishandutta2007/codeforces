//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int lg = 18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, q, st[maxn], ft[maxn], t, h[maxn], par[maxn][lg], a[maxn], b[maxn], c[maxn], ans[maxn];
vector<int> g[maxn], gt[maxn];

void dfs(int v){
	st[v] = t++;
	for(int u : g[v]){
		if(u == par[v][0]) continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		for(int i = 1; i < lg; i++){
			par[u][i] = par[par[u][i - 1]][i - 1];
		}
		dfs(u);
	}
	ft[v] = t;
	return;
}
int lca(int v, int u){
	if(h[v] < h[u]) swap(v, u);
	int dh = h[v] - h[u];
	for(int i = 0; i < lg; i++){
		if((dh >> i) & 1){
			v = par[v][i];
		}
	}
	for(int i = lg; i--;){
		if(h[v] >= (1 << i) && par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	if(v != u) v = par[v][0];
	return v;
}
priority_queue<pair<pair<pii, int>, int> > pq;
bool vis[maxn];

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	cin >> q;
	while(q--){
		int k, m;
		cin >> k >> m;
		vector<pii> vec;
		for(int i = 0; i < k; i++){
			cin >> a[i] >> b[i];
			vec.pb(Mp(st[a[i]], a[i]));
		}
		for(int i = 0; i < m; i++){
			cin >> c[i];
			vec.pb(Mp(st[c[i]], c[i]));
		}
		sort(all(vec));
		vector<pii> vec2 = vec;
		for(int i = 1; i < Sz(vec); i++){
			int x = lca(vec[i].S, vec[i - 1].S);
			vec2.pb(Mp(st[x], x));
		}
		sort(all(vec2));
		vector<int> stk;
		for(pii i : vec2){
			if(!stk.empty() && i.S == stk.back()) continue;
			while(!stk.empty() && ft[stk.back()] <= i.F){
				stk.pop_back();
			}
			if(!stk.empty()){
				gt[stk.back()].pb(i.S);
				gt[i.S].pb(stk.back());
			}
			stk.pb(i.S);
		}
		for(int i = 0; i < k; i++){
			pq.push(Mp(Mp(Mp(1, -i), 0), a[i]));
		}
		while(!pq.empty()){
			int v = pq.top().S;
			int d1 = -pq.top().F.F.F;
			int d2 = -pq.top().F.S;
			int vir = -pq.top().F.F.S;
			if(d1 == -1) d1 = 0;
			pq.pop();
			if(vis[v]) continue;
			vis[v] = 1;
			ans[v] = vir;
			for(int u : gt[v]){
				int dd2 = d2 + abs(h[v] - h[u]);
				int p1 = d1 + dd2 / b[vir];
				int p2 = dd2 % b[vir];
				if(p2 == 0){
					p1--;
					p2 = b[vir];
				}
				pq.push(Mp(Mp(Mp(-p1, -vir), -p2), u));
			}
		}
		for(pii i : vec2){
			vis[i.S] = 0;
			gt[i.S].clear();
		}
		for(int i = 0; i < m; i++){
			cout << ans[c[i]] + 1 << " ";
		}
		cout << "\n";
	}
	
	return 0;
}