// Problem: C. Complete the MST
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int maxn = 3e5 + 5;

struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

ll n, m;
vector<vector<int>> g;
vector<array<int, 3>> elist;
dsu D(0);

//copied code
std::set<int> adj[1<<18];
std::set<int> unvis;
 
void dfs(int x){
  unvis.erase(x);
  int z;
  for(auto y=unvis.begin();y!=unvis.end();y=unvis.upper_bound(z)){
    z=*y;
    if(!adj[x].count(z)){
	  D.join(x, z);
      dfs(z);
    }
  }
}
 
void solve1242B(){
  for(int i=1;i<=n;i++){
    unvis.insert(i);
  }
  for(int i=1;i<=n;i++){
    if(unvis.count(i)){
      dfs(i);
    }
  }
//end copy
}

void finish(ll cost = 0) {
	for(auto [x, y, w] : elist) {
		cost += w*D.join(x, y);
	}
	cout << cost << '\n';
	exit(0);
}

ll uwu(int x, int y, int z, vector<array<int, 2>> &f) {
	dsu d(n+1);
	for(auto [a, b] : f) if(a != x || b != y) d.join(a, b);
	ll ans = 0;
	for(auto [A, B, C] : elist) {
		if(C > z) ans += z*d.join(x, y);
		ans += C*d.join(A, B);
	}
	ans += z*d.join(x, y);
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int xr = 0;
	cin >> n >> m;
	D = dsu(n+1);
	g.resize(n+1);
	for(int f, t, w, i = 0; i < m; i++) {
		cin >> f >> t >> w;
		xr ^= w;
		adj[f].insert(t);
		adj[t].insert(f);
		g[f].push_back(t);
		g[t].push_back(f);
		elist.push_back({f, t, w});
	}
	sort(all(elist), [](auto &a, auto &b) { return a[2] < b[2]; });
	ll left = n;
	left = left*(left-1)/2;
	left -= m;
	if(left >= n) {//there's a cycle somewhere
		solve1242B();
		finish();
	}
	vector<vector<int>> have(n+1, vector<int>(n+1));
	for(auto [x, y, z] : elist) have[x][y] = have[y][x] = 1;
	int nocyc = 1;
	//cout << xr << endl;
	vector<array<int, 2>> check;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++) if(!have[i][j])
			nocyc &= D.join(i, j), check.push_back({i, j});
	if(!nocyc) finish();
	else {
		ll ans = 1ll<<60;
		for(auto [x, y] : check)
			ans = min(ans, uwu(x, y, xr, check));
		cout << ans << '\n';
	}
}