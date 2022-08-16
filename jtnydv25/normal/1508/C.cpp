#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

struct dsu{
    int n;
    vector<int> par;
    dsu(int n) : n(n), par(n){
        iota(par.begin(), par.end(), 0);
    }
    int root(int x){
        return x == par[x] ? x : (par[x] = root(par[x]));
    }
    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return 0;
        par[x] = y;
        return 1;
    }
};


const int N = 200005;
int a[N], b[N], w[N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m; cin >> n >> m;

	vector<set<int>> adj(n);
	map<pii, int> weights;
	vector<int> perm(m);
	int XOR = 0;
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i] >> w[i];
		a[i]--; b[i]--;
		if(a[i] > b[i]) swap(a[i], b[i]);
		adj[a[i]].insert(b[i]);
		adj[b[i]].insert(a[i]);
		perm[i] = i;
		XOR ^= w[i];
	}
	sort(all(perm), [&](int i, int j){return w[i] < w[j];});
	dsu D(n);
	set<int> unvisited;
	for(int i = 0; i < n; i++) unvisited.insert(i);
	vector<pii> edges;
	vector<int> ID(n);
	vector<vector<int>> comps;
	vector<int> curr;
	function<void(int)> dfs = [&](int s){
		int lo = 0;
		curr.push_back(s);
		ID[s] = comps.size();
		unvisited.erase(s);
		while(!unvisited.empty()){
			auto it = unvisited.lower_bound(lo);
			if(it == unvisited.end()) return;
			int u = *it;
			if(adj[s].count(u)){
				lo = u + 1;
				continue;
			} else{
				edges.push_back({s, u});
				D.merge(s, u);
				dfs(u);
			}
		}
	};
	bool cycle = false;
	for(int i = 0; i < n; i++){
		if(unvisited.count(i)){
			curr.clear();
			dfs(i);
			comps.push_back(curr);
		}
	}
	ll cost = 0;
	int min_not = XOR;
	dsu D2(n);
	vector<bool> bad(m);
	for(int e : perm){
		if(D.merge(a[e], b[e])){
			cost += w[e];
			D2.merge(a[e], b[e]);
		} else bad[e] = true;
	}
	for(int e : perm) if(bad[e] && D2.merge(a[e], b[e])){
		min_not = min(min_not, w[e]);
		break;
	}
	vector<int> num(comps.size());
	// trace(cost, XOR);
	for(int i = 0; i < m; i++) if(ID[a[i]] == ID[b[i]]) num[ID[a[i]]]++;
	for(int i = 0; i < sz(comps); i++){
		int _n = sz(comps[i]);
		ll total = (_n * 1ll * (_n - 1)) / 2;
		if(num[i] + _n - 1 != total){
			cout << cost << endl;
			return 0;
		}
	}

	cout << cost + min_not << endl;
}