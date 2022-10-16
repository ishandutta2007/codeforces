#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
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

const int MAXN = 1e6;

int n;
vector<int> g[MAXN];
int t, in[MAXN], low[MAXN];
vector<int> s;
bool stacked[MAXN];
int scc[MAXN], scc_n;
bool value[MAXN];

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

int N, M;

int getN(int a, int b) { return a * N + b; }

void add_edge(int a, int b, int c, int d) {
   debug(a, b, c, d);
   g[getN(a, b)].push_back(getN(c, d));
}

set<int> X[MAXN];

int get_low(int x, set<int> &T) {

   auto itr = T.upper_bound(x);
   if (itr != T.begin())
      return *(--itr);

   return -1;
}

int32_t main() {

   cin >> N >> M;

   vector<int> V;

   rep(i, N) {
      string S;
      cin >> S;
      rep(j, M) if (S[j] == '#') { X[j].insert(N - i - 1); }
   }

   rep(i, M) {
      for (auto v : X[i]) {
         if (X[i].count(v + 1))
            add_edge(i, v, i, v + 1);

         int t = get_low(v, X[i + 1]);
         if (t != -1)
            add_edge(i, v, i + 1, t);

         t = i == 0 ? -1 : get_low(v, X[i - 1]);
         if (t != -1)
            add_edge(i, v, i - 1, t);

         t = get_low(v - 1, X[i]);

         if (t != -1)
            add_edge(i, v, i, t);
      }
   }

   n = N * M;

   tarjan_scc();

   set<int> zle;
   set<int> A;

   rep(j, M) for (auto v : X[j]) {
      int i = getN(j, v);
      A.insert(scc[i]);
      for (int x : g[i])
         if (scc[x] != scc[i])
            zle.insert(scc[x]);
   }

   cout << sz(A) - sz(zle) << endl;
}