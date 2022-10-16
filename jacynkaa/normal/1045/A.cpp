#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]
#ifdef LOCAL
ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
template <class L, class R, class S> ostream &operator<<(ostream &out, tuple<L, R, S> p) {
   auto &[a, b, c] = p;
   return out << "(" << a << ", " << b << ", " << c << ")";
}
template <class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
   out << '{';
   for (auto it = a.begin(); it != a.end(); it = next(it))
      out << (it != a.begin() ? ", " : "") << *it;
   return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts> void dump(T a, Ts... x) {
   cerr << a << ", ";
   dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#define debug(...) 42
#endif

namespace RMQ {
   vector<vector<int>> idx;

   vector<pii> init(const vector<int> &V, int &cnt) {
      int N = sz(V), on = 1, depth = 1;
      while (on < N)
         on *= 2, depth++;
      idx.assign(depth, V);
      vector<pii> res;

      rep(i, depth - 1) rep(j, N) {
         idx[i + 1][j] = cnt++;
         // for (int k = j; k < (min(N, j + (2 << i))); k++)
         //    res.emplace_back(idx[i + 1][j], idx[0][k]);
         res.emplace_back(idx[i + 1][j], idx[i][j]);
         res.emplace_back(idx[i + 1][j], idx[i][min(N - 1, j + (1 << i))]);
      }
      return res;
   }

   pii query(int a, int b) {
      assert(a < b); // or return i n f i f a == b
      int dep = 31 - __builtin_clz(b - a);
      return {idx[dep][a], idx[dep][b - (1 << dep)]};
   }
}; // namespace RMQ

const int MAXN = 1e6;

struct edge {

   int v, rev;
   int res;
   int org;
};
vector<edge> nbrs[MAXN]; // puste przed dodawaniem krawedzi!
int start[MAXN], dist[MAXN];

void addEdge(int a, int b, int c) {
   nbrs[a].pb({b, sz(nbrs[b]), c, c});
   nbrs[b].pb({a, sz(nbrs[a]) - 1, 0, 0});
}

bool bfs(int s, int t, int n) {
   rep(i, n) dist[i] = -1;
   dist[s] = 0;
   queue<int> q;
   q.push(s);
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (edge &e : nbrs[u])
         if (e.res > 0 && dist[e.v] == -1) {
            dist[e.v] = dist[u] + 1;
            q.push(e.v);
         }
   }
   return dist[t] != -1;
}
int dfs(int x, int t, int mini) {
   int ans = 0;
   if (x == t)
      return mini;
   if (mini <= 0)
      return 0;
   for (int &i = start[x]; i < sz(nbrs[x]); ++i) {
      edge &e = nbrs[x][i];
      if (dist[x] + 1 == dist[e.v] && e.res > 0) {
         int added = dfs(e.v, t, min(mini, e.res));
         e.res -= added;
         nbrs[e.v][e.rev].res += added;
         mini -= added;
         ans += added;
         if (mini <= 0)
            break;
      }
   }
   return ans;
}
int maxFlow(int s, int t, int n) {
   int ans = 0;
   while (bfs(s, t, n)) {
      rep(i, n) start[i] = 0;
      ans += dfs(s, t, 1e9);
   }
   return ans;
}

const int inf = 1e9;

void add_edge(int a, int b, int c) { addEdge(a, b, c); }

void dfs(vector<vector<int>> &G, int x, vector<int> &odp, int target) {
   odp.push_back(x);
   debug(odp);
   if (x == target)
      return;
   int y = G[x].back();
   G[x].pop_back();

   dfs(G, y, odp, target);
}

int get_m(int a) { return a + 1; }
int get_rm(int a) { return a - 1; }

int32_t main() {
   _upgrade;
   int n, m;
   cin >> n >> m;

   vector<int> V(m);
   int source = 0;
   int target = 1;
   int cnt = 2;
   rep(i, m) V[i] = cnt++;

   auto E = RMQ::init(V, cnt);

   rep(i, m) add_edge(V[i], target, 1);

   for (auto [a, b] : E) {
      add_edge(a, b, inf);
   }

   map<int, vector<int>> B;
   int s = cnt;

   rep(i, n) {
      int t;
      cin >> t;
      int idx = cnt++;
      if (t == 0) {
         add_edge(source, idx, 1);
         int k;
         cin >> k;
         rep(i, k) {
            int a;
            cin >> a;
            add_edge(idx, get_m(a), 1);
         }
      }
      if (t == 1) {
         add_edge(source, idx, 1);
         int l, r;
         cin >> l >> r;
         pii T = RMQ::query(l - 1, r);
         add_edge(idx, T.st, 1);
         add_edge(idx, T.nd, 1);
      }
      if (t == 2) {
         add_edge(source, idx, 2);
         vector<int> Q(3);
         rep(i, 3) {
            cin >> Q[i];
            add_edge(idx, get_m(Q[i]), 1);
         }
         B[idx] = Q;
      }
   }

   int res = maxFlow(source, target, cnt);
   // vector<mii> C = M;
   // debug(C);
   // int res = edmondsKarp(M, source, target);
   // debug(res);

   vector<vector<int>> G(cnt);
   // debug(M, C);
   rep(i, MAXN) {
      for (auto [a, _, c, d] : nbrs[i]) {
         rep(l, d - c) G[i].push_back(a);
      }
   }

   debug(G);

   map<int, set<int>> R;

   rep(i, res) {
      vector<int> odp;
      dfs(G, source, odp, target);
      debug(odp);
      int bron = odp[1];
      int statek = get_rm(odp[sz(odp) - 2]);
      R[bron].insert(statek);
   }

   set<int> zabronione;

   for (auto [a, Q] : B) {
      if (sz(R[a]) == 1) {
         for (int c : Q)
            if (R[a].insert(c).nd) {
               zabronione.insert(c);
               break;
            }
      }
   }

   cout << res << endl;

   for (auto [a, X] : R) {
      for (auto x : X)
         if (zabronione.count(x) == 0 || sz(X) > 1) {
            cout << a - s + 1 << " " << x << endl;
         }
   }
}