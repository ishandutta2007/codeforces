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

int N, M, H;
int u[100500];
vector<int> inv[100500];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> H;
    for(int i = 0; i < N; i++) {
        cin >> u[i];
    }
    UnWeightedGraph g(N);
    for(int i = 0; i < M; i++) {
        int u1, u2;
        cin >> u1 >> u2;
        u1--;
        u2--;
        if((u[u1] + 1) % H == u[u2]) {
            g[u1].push_back(u2);
        }
        swap(u1, u2);
        if((u[u1] + 1) % H == u[u2]) {
            g[u1].push_back(u2);
        }
    }
    UnWeightedGraph t(N);
    StronglyConnectedComponents<UnWeightedGraph> SCC(g);
    SCC.build(t);
    /*
    for(int i = 0; i < N; i++) {
        cout << SCC[i] << endl;
    }
    */
   /*
    cerr << t.size() << endl;
    for(int i = 0; i < t.size(); i++) {
        cerr << i << ":";
        for(auto val : t[i]) cerr << val << " ";
        cerr << endl;
    }
    */
    for(int i = 0; i < N; i++) {
        inv[SCC[i]].push_back(i + 1);
    }
    int ans = -1;
    for(int i = 0; i < t.size(); i++) {
        if(!t[i].empty()) continue;
        //cerr << i << endl;
        if(ans == -1 or inv[i].size() < inv[ans].size()) {
            ans = i;
        }
    }
    cout << inv[ans].size() << endl;
    for(auto val : inv[ans]) cout << val << " ";
    cout << endl;
    return 0;
}