#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
vi p;
map<pair<int, int>, bool> d;
vvi ans;

int get_par(int a) {
	if(p[a] == a) {
		return a;
	}
	int par = get_par(p[a]);
	p[a] = par;
	return par;
}

bool is_one(int a, int b) {
	return get_par(a) == get_par(b);
}

void join(int a, int b) {
	if(is_one(a, b)) {
		return;
	}
	a = get_par(a);
	b = get_par(b);
	p[a] = b;
}

bool dfs1(int v, int p, int u, int now) {
	if(v == u) {
		ans[now].push_back(v);
		return true;
	}
	for(int next : g[v]) {
		if(next == p) {
			continue;
		}
		bool res = dfs1(next, v, u, now);
		if(res) {
			d[{min(v, next), max(v, next)}] = !d[{min(v, next), max(v, next)}];
			ans[now].push_back(v);
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    g.resize(n);
    p.resize(n);
    for(int i = 0; i < n; i++) {
    	p[i] = i;
    }
    for(int i = 0; i < m; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	if(is_one(v, u)) {
    		continue;
    	}
    	g[v].push_back(u);
    	g[u].push_back(v);
    	join(v, u);
    }
    int q;
    cin >> q;
    ans.resize(q);
    for(int o = 0; o < q; o++) {
    	int a, b;
    	cin >> a >> b;
    	--a;
    	--b;
    	dfs1(a, -1, b, o);
    }
    bool ok = true;
    for(int v = 0; v < n; v++) {
    	for(int u : g[v]) {
    		if(d[{min(v, u), max(v, u)}]) {
    			ok = false;
    			break;
    		}
    	}
    	if(!ok) {
    		break;
    	}
    }
    if(ok) {
    	cout << "YES\n";
    	for(int i = 0; i < q; i++) {
    		cout << ans[i].size() << '\n';
    		for(int j = ans[i].size() - 1; j >= 0; j--) {
    			cout << ans[i][j] + 1 << ' ';
    		}
    		cout << '\n';
    	}
    	return 0;
    }
    cout << "NO\n";
    vector<set<int>> g1(n);
    for(int v = 0; v < n; v++) {
    	for(int u : g[v]) {
    		if(d[{min(v, u), max(v, u)}]) {
    			g1[v].insert(u);
    		}
    	}
    }
    vi cand;
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	if(g1[i].size() == 1) {
    		cand.push_back(i);
    	}
    }
    while(!cand.empty()) {
    	int v = cand[cand.size() - 1];
    	cand.pop_back();
    	if(g1[v].empty()) {
    		continue;
    	}
    	++ans;
    	while(!g1[v].empty()) {
    		int u = *(g1[v].begin());
    		g1[v].erase(g1[v].begin());
    		if(g1[v].size() == 1) {
    			cand.push_back(v);
    		}
    		g1[u].erase(g1[u].find(v));
    		if(g1[u].size() == 1) {
    			cand.push_back(u);
    		}
    		v = u;
    	}
    }
    cout << ans;


}