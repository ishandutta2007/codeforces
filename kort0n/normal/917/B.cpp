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
vector<vector<i_i>> paths;
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
vector<i_i> toposo;

bool dp[100][100][26];


int main() {
    int N, M;
    cin >> N >> M;
    UnWeightedGraph g(N), t;
    paths.resize(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(b);
        paths[a].push_back({b, (int)(c - 'a')});
    }
    StronglyConnectedComponents<UnWeightedGraph> SCC(g);
    SCC.build(t);
    for(int i = 0; i < N; i++) toposo.push_back({SCC[i], i});
    sort(toposo.begin(), toposo.end());
    vector<int> v;
    for(auto tmp : toposo) v.push_back(tmp.second);
    vector<int> inv(N);
    for(int i = 0; i < N; i++) inv[v[i]] = i;
    for(int c = 25; c >= 0; c--) {
        for(int i = N - 1; i >= 0; i--) {
            for(int b = N - 1; b > i; b--) {
                for(auto tmp : paths[v[i]]) {
                    int to = inv[tmp.first];
                    int cnow = tmp.second;
                    if(cnow < c) continue;
                    dp[i][b][c] |= !dp[b][to][cnow];
                }
            }
            for(int a = N - 1; a > i; a--) {
                for(auto tmp : paths[v[a]]) {
                    int to = inv[tmp.first];
                    int cnow = tmp.second;
                    if(cnow < c) continue;
                    dp[a][i][c] |= !dp[i][to][cnow];
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[inv[i]][inv[j]][0]) cout << "A";
            else cout << "B";
        }
        cout << endl;
    }
    return 0;
}