#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n, target, a, b, dpt[N], fth[N];
vector <vector <int>> v;


int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
  static vector<int> sz(g.size());
  function<void (int, int)> get_sz = [&](int u, int prev) {
    sz[u] = 1;
    for (auto v : g[u]) if (v != prev && !dead[v]) {
      get_sz(v, u);
      sz[u] += sz[v];
    }
  };
  get_sz(root, -1);
  int n = sz[root];
  function<int (int, int)> dfs = [&](int u, int prev) {
    for (auto v : g[u]) if (v != prev && !dead[v]) {
      if (sz[v] > n / 2) {
        return dfs(v, u);
      }
    }
    return u;
  };
  return dfs(root, -1);
}
// Then, using this centroid, you can implement centroid decomposition like this.

int dist(int node) {
	int ans;
	cout << "d " << node << endl;
	cin >> ans;
	return ans;
}

int sec(int node) {
	int ans = 0;
	cout << "s " << node << endl;
	cin >> ans;
	return ans;
}


void CentroidDecomposition(const vector<vector<int>> &g) {
  int n = (int) g.size();
  vector<bool> dead(n, false);

  function<void (int, int)> rec = [&](int start, int lvl) {
    int c = OneCentroid(start, g, dead);
  	dbg(c);
    dead[c] = true;

    // dbg(c, lvl);
    // val[c] = 'A' + lvl;
    // c is centroid at level lvl

    int nxt, dc = dist(c);
    if(dc == 0) {
    	cout << "! " << c << endl;
    	exit(0);
    }

    dbg(dc, dpt[c], target);
    
    if(target == dpt[c] + dc) {
    	nxt = sec(c);
    } else {
    	nxt = fth[c];
    }

    // for (auto u : g[c]) if (!dead[u]) {
    //   rec(u, lvl + 1);
    // }

    rec(nxt, lvl + 1);

    dead[c] = false;
  };
  
  rec(1, 0);
}


void dfs(int node, int t = -1, int d = 0) {
	fth[node] = t;
	dpt[node] = d;
	for(auto i : v[node])
		if(i != t)
			dfs(i, node, d + 1);
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	v = vector <vector<int> > (n + 1, vector <int>());

	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	target = dist(1);
	
	dfs(1);

	if(target == 0) return cout << "! 1" << endl, 0;
	// dbg(target);
	CentroidDecomposition(v);
}