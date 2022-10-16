#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<vector<int>> UnWeightedGraph;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
template< typename G >
struct StronglyConnectedComponents {
  const G &g;
  UnWeightedGraph gg, rg;
  vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return (comp[k]);
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(UnWeightedGraph &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};


void solve() {
    int N, M;
    cin >> N >> M;
    UnWeightedGraph G(N);
    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a == b) continue;
        G[a].push_back(b);
    }
    UnWeightedGraph H(N);
    StronglyConnectedComponents<UnWeightedGraph> SCC(G);
    SCC.build(H);
    vector<int> zero;
    vector<int> one;
    for(int i = 0; i < N; i++) {
        if(SCC[i] == 0) zero.push_back(i + 1);
        else one.push_back(i + 1);
    }
    //for(auto val : zero) cerr << val << " ";
    //cerr << endl;
    if(zero.size() == N) {
        cout << "No" << "\n";
        return;
    }
    cout << "Yes" << "\n";
    cout << one.size() << " " << zero.size() << "\n";
    for(auto val : one) cout << val << " ";
    cout << "\n";
    for(auto val : zero) cout << val << " ";
    cout << "\n";
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}