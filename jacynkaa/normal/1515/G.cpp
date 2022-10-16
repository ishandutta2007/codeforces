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
#define int long long

namespace SCC {

   int n;
   const int N = 1e6;

   vector<int> g[N];

   int t, in[N], low[N];
   vector<int> s;
   bool stacked[N];
   int scc[N], scc_n;

   void tarjan(int u) {
      low[u] = in[u] = t++;
      s.push_back(u);
      stacked[u] = true;
      for (int v : g[u]) {
         if (in[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
         } else if (stacked[v])
            low[u] = min(low[u], in[v]);
      }
      if (low[u] == in[u]) {
         for (;;) {
            int v = s.back();
            s.pop_back();
            stacked[v] = false;
            scc[v] = scc_n;
            if (v == u)
               break;
         }
         scc_n++;
      }
   }
   void tarjan_scc() {
      rep(i, n) {
         in[i] = low[i] = -1;
         stacked[i] = false;
      }
      scc_n = t = 0;
      rep(i, n) if (in[i] == -1) tarjan(i);
   }
} // namespace SCC

const int MAXN = 1e6;
int len[MAXN];
bool vis[MAXN];
int GC[MAXN];
vector<pii> G[MAXN];

void dfs(int x) {

   vis[x] = true;
   for (auto [y, a] : G[x])
      if (SCC::scc[x] == SCC::scc[y]) {
         if (!vis[y]) {
            debug(x + 1, y + 1, a);
            len[y] = len[x] + a;
            dfs(y);
         } else {

            int r = abs(len[x] + a - len[y]);
            debug(x + 1, y + 1, r);
            GC[SCC::scc[x]] = __gcd(r, GC[SCC::scc[x]]);
         }
      }
}

int32_t main() {
   _upgrade;
   int n, m;
   cin >> n >> m;

   SCC::n = n;

   rep(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      G[--a].push_back({--b, c});
      SCC::g[a].push_back(b);
   }
   SCC::tarjan_scc();

   rep(i, n) debug(SCC::scc[i]);

   rep(i, n) if (!vis[i]) dfs(i);

   rep(i, n) debug(i, GC[i]);

   int q;
   cin >> q;

   rep(i, q) {
      int v, s, t;
      cin >> v >> s >> t;
      --v;
      if (s == 0) {
         cout << "YES\n";
         continue;
      }
      int g = GC[SCC::scc[v]];
      debug(g);

      int a = __gcd(t, s);
      int b = __gcd(g, t);
      debug(a, b);
      cout << ((a % b == 0) ? "YES\n" : "NO\n");
   }
}