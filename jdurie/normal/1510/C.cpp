#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin>>x;
#define F(i,l, r) for (ll i=(l); i<(r); ++i)
#define all(x) begin(x), end(x)
#define K first
#define V second
#define N 100010

vector<ll> graph[N];
set<pl> cyc, ans;
ll dep[N], par[N];
bool used[N];

void dfs(ll i, ll p) {
	par[i] = p;
	dep[i] = dep[p] + 1;
	for(ll j : graph[i]) if(!dep[j]) dfs(j, i);
	else if(dep[j] < dep[i] - 1) {
		cyc.insert({i, j}), cyc.insert({j, i});
		ll k = i;
		while(k - j) {
			cyc.insert({k, par[k]}), cyc.insert({par[k], k});
			k = par[k];
		}
	}
}

pl doshit(ll i, ll p) {
	used[i] = true;
	vector<ll> v; pair<pl, ll> q = {{0, 0}, 0};
	for(ll j : graph[i]) if(j - p && !cyc.count({i, j})) {
		pl h = doshit(j, i);
		v.push_back(h.K);
		if(h.V) q = {h, j};
	}
	if(!v.size()) return {i, -1};
	if(q.V) {
		ll id = 0; while(v[id] - q.K.K) id++;
		swap(v[0], v[id]);
	}
	ll ret = -1;
	if(i - p) { ret = v.back(); v.pop_back(); }
	while(v.size() > 1) {
		ll a = v.back(); v.pop_back();
		ll b = v.back(); v.pop_back();
		ans.insert({a, b});
	}
	if(v.size() == 1) {
		if(!q.V) { ans.insert({v[0], i}); return {ret, v[0]}; }
		else {
			ans.erase({q.K.V, q.V});
			if(~q.K.V) ans.insert({q.K.V, q.K.K});
		}
	}
	return {ret, 0};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1) {
		G(n) G(e)
		if(!n) break;
		while(e--) {
			G(k) G(lst)
			while(--k) {
				G(x)
				graph[lst].push_back(x);
				graph[x].push_back(lst);
				lst = x;
			}
		}
		dfs(1, N - 1);
		F(i, 1, n + 1) if(!used[i]) doshit(i, i);
		cout << ans.size() << '\n';
		for(pl p : ans) cout << p.K << ' ' << p.V << '\n';
		F(i, 1, n + 1) graph[i].clear(), dep[i] = par[i] = used[i] = 0;
		ans.clear(); cyc.clear();
	}
}