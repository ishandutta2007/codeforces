#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
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

const long long INF = 1e18;
//const ll mod = 1000000007;
typedef vector<vector<int>> UnWeightedGraph;
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

ll N, M;
vector<ll> paths[2][210000];
UnWeightedGraph g, t;
bool checked[2][201000];
void dfs(int idx, int now) {
    if(checked[idx][now]) return;
    checked[idx][now] = true;
    for(auto to : paths[idx][now]) {
        dfs(idx, to);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    g.resize(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        paths[0][a].push_back(b);
        paths[1][b].push_back(a);
    }
    StronglyConnectedComponents<UnWeightedGraph> SCC(g);
    SCC.build(t);
    set<int> already;
    for(int i = 0; i < N; i++) {
        if(already.find(SCC[i]) != already.end()) {
            cout << -1 << endl;
            return 0;
        }
        already.insert(SCC[i]);
    }
    string ans;
    int ansval = 0;
    for(int i = 0; i < N; i++) {
        if(checked[0][i] or checked[1][i]) {
            ans.push_back('E');
        } else {
            ans.push_back('A');
            ansval++;
        }
        dfs(0, i);
        dfs(1, i);
    }
    cout << ansval << endl;
    cout << ans << endl;
    return 0;
}