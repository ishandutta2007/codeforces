// Problem: G.  
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 200200;
int n, m, q;
vector<array<int, 2>> g[N];
map<array<int, 2>, int> W, L;
vector<array<int, 4>> ops;
multiset<ll> ex;
void ins(vector<array<int, 2>> &v, array<int, 2> u) {
	for(auto &i : v) {
		if(u < i)
			swap(u, i);
	}
	v.push_back(u);
}
void kill(vector<array<int, 2>> &v, array<int, 2> u) {
	v.erase(find(all(v), u));
}
ll add_edge(int f, int t, int w) {
	// clr(f, t);
	ops.push_back({1, f, t, w});
	// for(auto i : ops.back()) cout << i << " "; cout << endl;
	ins(g[f], {w, t});
	ins(g[t], {w, f});
	ex.insert(w);
	for(int Z = 2; Z--; swap(f, t))
	if(g[f].size() > 3) {
		ops.push_back({-1, f, g[f][3][1], g[f][3][0]});
		// for(auto i : ops.back()) cout << i << " "; cout << endl;
		kill(g[f], g[f].back());
		kill(g[g[f][3][1]], {g[f][3][0], f});
		ex.erase(ex.find(g[f][3][0]));
	}
	
	ll ans = 0;
	int i = 0, j = 0;
	auto it = ex.begin();
	while(it != ex.end()) {
		if(j < g[t].size() && g[t][j][1] == f) j++;
		if(i < g[f].size() && g[f][i][0] == *it)
			it++, i++;
		else if(j < g[t].size() && g[t][j][0] == *it)
			it++, j++;
		else
			break;
	} 
	if(it == ex.end())
		ans = 1ll<<40;
	else 
		ans = w + *it;
	// cout << f << " " << t << " " << w << " " << ans << endl;
	// rlc(f, t);
	return ans;
}
vector<array<int, 3>> tree[2*N];
void add(int v, int l, int r, int ql, int qr, array<int, 3> edge) {
	if(qr < l || r < ql)
		return;
	if(ql <= l && r <= qr) {
		tree[v].push_back(edge);
		return;
	}
	int m = (l+r)/2;
	add(2*v, l, m, ql, qr, edge);
	add(2*v+1, m+1, r, ql, qr, edge);
}
vector<ll> ans;
void dfs(int v, int l, int r, ll best) {
	int bk = ops.size();
	for(auto [x, y, z] : tree[v])
		best = min(best, add_edge(x, y, z));
	if(l == r) {
		ans[l] = min(ans[l], best);
	} else {
		int m = (l+r)/2;
		dfs(2*v, l, m, best);
		dfs(2*v+1, m+1, r, best);
	}
	while(ops.size() > bk) {
		auto [tp, f, t, w] = ops.back();
		// clr(f, t);
		if(tp == 1) {
			kill(g[f], {w, t});
			kill(g[t], {w, f});
			ex.erase(ex.find(w));
		} else {
			ins(g[f], {w, t});
			ins(g[t], {w, f});
			ex.insert(w);
		}
		// rlc(f, t);
		ops.pop_back();
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m;	
	ll best = 1ll<<40;
	vector<multiset<ll>> dum(n+1);
	multiset<ll> rip;
	for(int i = 1; i <= n; i++)
		rip.insert(-1);
	auto eval = [&](int v) {
		if(dum[v].size() < 3)
			return -1ll;
		auto it = dum[v].begin();
		ll ans = 0;
		for(int i = 0; i < 3; i++) {
			ans += *it;
			it++;
		}
		return ans;
	};
	auto add_dum = [&](int v, int w, int T) {
		rip.erase(rip.find(eval(v)));
		if(T == 1)
			dum[v].insert(w);
		if(T == -1)
			dum[v].erase(dum[v].find(w));
		rip.insert(eval(v));
	};
	for(int f, t, w, i = 0; i < m; i++) {
		cin >> f >> t >> w;
		if(f > t) swap(f, t);
		// best = min(best, add_edge(f, t, w));
		add_dum(f, w, 1);
		add_dum(t, w, 1);
		W[{f, t}] = w;
		L[{f, t}] = 0;
	}
	cin >> q;
	ans.resize(q+1, 1ll<<40);
	auto uh = rip.upper_bound(-1);
	if(uh != rip.end())
		ans[0] = *uh;
	for(int t, x, y, w, i = 1; i <= q; i++) {
		cin >> t >> x >> y;
		if(x > y) swap(x, y);
		if(t == 0) {
			add(1, 0, q, L[{x, y}], i-1, {x, y, W[{x, y}]});
			add_dum(x, W[{x, y}], -1);
			add_dum(y, W[{x, y}], -1);
			L[{x, y}] = -1;
		} else {
			cin >> w;
			W[{x, y}] = w;
			L[{x, y}] = i;
			add_dum(x, w, 1);
			add_dum(y, w, 1);
		}
		auto uh = rip.upper_bound(-1);
		if(uh != rip.end())
			ans[i] = *uh;
	}
	for(auto [T, s] : L) if(s > -1) {
		add(1, 0, q, s, q, {T[0], T[1], W[T]});
	}
	dfs(1, 0, q, best);
	for(auto i : ans)
		cout << i << '\n';
}