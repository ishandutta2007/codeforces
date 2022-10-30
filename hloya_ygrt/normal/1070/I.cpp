//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


//typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
//typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 1e6 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
//const int pp = 41;

#define next ajksdslk

typedef long long LL;

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

int ans[601];
pii pr[maxn];
vector<pair<int, int> > g[601];

void solve() {
    memset(ans, 0, sizeof(ans));
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
//        a--, b--;
        g[a].pb(mp(a, i + 1));
        g[b].pb(mp(b, i + 1));
    }

    int s = 0;
    int t = m + n + 1;

    vector<pair<int, pii> > edges;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += max(0, (int)g[i].size() - k);
        edges.pb(mp(2 * max(0, (int)g[i].size() - k), mp(s, i)));
    }
    for (int i = 1; i <= m; i++) {
        edges.pb(mp(1, mp(i + n, t)));
    }
    int cnt = m + n + 2;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < g[i].size(); j++)
            for (int k = j + 1; k < g[i].size(); k++) {
                int u = g[i][j].fst, v = g[i][k].fst;
                int iu = g[i][j].snd, iv = g[i][k].snd;
                if (u > v) swap(u, v);
                pr[cnt] = mp(iu, iv);
                edges.pb(mp(2, mp(i, cnt)));
                edges.pb(mp(1, mp(cnt, iu + n)));
                edges.pb(mp(1, mp(cnt, iv + n)));
                cnt++;
            }
    Dinic flow(cnt + 5);
    for (auto e : edges) {
        flow.AddEdge(e.snd.fst, e.snd.snd, e.fst);
    }
    int res = flow.MaxFlow(s, t);
    if (res != sum * 2) {
        for (int i = 0; i < m; i++)
            cout << 0 << ' ';
        cout << "\n";
        return;
    }

    vector<pair<int, int> > asd;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 0; j < flow.g[i].size(); j++) {
            Edge e = flow.E[flow.g[i][j]];
            if (e.flow == 1) {
                int pr = e.v;
                for (auto k : flow.g[pr]) {
                    Edge e2 = flow.E[k];
                    if (e2.flow == 1) {
                        v.pb(e2.v - n);
                    }
                }
            } else if (e.flow == 2) {
                asd.pb(pr[e.v]);
            }
        }
        assert(v.size() % 2 == 0);
        for (int j = 0; j < v.size(); j += 2) {
            asd.pb(mp(v[j], v[j + 1]));
        }
    }

    int kek = 1;
    for (auto e : asd) {
        ans[e.fst] = ans[e.snd] = kek++;
    }
    for (int i = 1; i <= m; i++) {
        if (!ans[i])
            ans[i] = kek++;
        cout << ans[i] << ' ';
    }
    cout << "\n";
}

int main() {
//    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--) solve();
}