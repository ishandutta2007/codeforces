#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <int> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 100100;
int n, k, m, a, b;
char val[N];

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

void CentroidDecomposition(const vector<vector<int>> &g) {
  int n = (int) g.size();
  vector<bool> dead(n, false);

  function<void (int, int)> rec = [&](int start, int lvl) {
    int c = OneCentroid(start, g, dead);           //2
    dead[c] = true;                                //2
    for (auto u : g[c]) if (!dead[u]) {
      rec(u, lvl + 1);                                //3
    }

    // dbg(c, lvl);
    val[c] = 'A' + lvl;

    dead[c] = false;                               //5
  };
  
  rec(0, 0);                                                //1
}

vector <vector <int> > v;

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n;
  v = vector<vector <int>> (n, vector <int>());
  for(int i = 1; i < n; i++) {
    cin >> a >> b;
    a--; b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  CentroidDecomposition(v);

  for(int i = 0; i < n; i++) cout << val[i] << ' ';
}