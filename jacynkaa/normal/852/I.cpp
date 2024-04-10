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

#define int long long

const int SS = 400;

struct Query {
   int l, r, idx, lca;
   bool operator<(Query other) const {
      if (l / SS != (other.l) / SS)
         return l < other.l;
      return ((l / SS) & 2) ? r < other.r : r > other.r;
   }
};

typedef vector<int> vi;
template <class T> struct RMQ {
   vector<vector<T>> jmp;
   RMQ(const vector<T> &V) : jmp(1, V) {
      for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
         jmp.emplace_back(sz(V) - pw * 2 + 1);
         fwd(j, 0, sz(jmp[k])) jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
      }
   }
   T query(int a, int b) {
      assert(a < b); // or return inf if a == b
      int dep = 31 - __builtin_clz(b - a);
      return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
   }
};

struct LCA {
   int T = 0;
   vi time, path, ret;
   RMQ<int> rmq;

   LCA(vector<vi> &C) : time(sz(C)), rmq((dfs(C, 0, -1), ret)) {}
   void dfs(vector<vi> &C, int v, int par) {
      time[v] = T++;
      trav(y, C[v]) if (y != par) {
         path.push_back(v), ret.push_back(time[v]);
         dfs(C, y, v);
      }
   }

   int lca(int a, int b) {
      if (a == b)
         return a;
      tie(a, b) = minmax(time[a], time[b]);
      return path[rmq.query(a, b)];
   }
};

const int MAXN = 2e5 + 99;
pii node[MAXN];
ll odp[MAXN];
int cnt[2][MAXN];
bool included[MAXN];
int st[MAXN];
int en[MAXN];
ll res = 0;
int n;
vector<vector<int>> G;
vector<int> S;

void dfs(int x, int &cnt, int p = -1) {
   S.push_back(x);
   st[x] = cnt++;
   for (int y : G[x])
      if (y != p)
         dfs(y, cnt, x);
   S.push_back(x);
   en[x] = cnt++;
}

void add(int x) {
   auto [a, b] = node[x];
   cnt[a][b]++;
   res += cnt[a ^ 1][b];
}

void remove(int x) {
   auto [a, b] = node[x];
   cnt[a][b]--;
   res -= cnt[a ^ 1][b];
}

void change(int x) {
   int a = S[x];
   if (included[a] = !included[a])
      add(a);
   else
      remove(a);
}

#define NO_LCA -1

void solve(vector<Query> V) {
   sort(all(V));
   int cur_l = 0;
   int cur_r = -1;
   for (auto [l, r, idx, lca] : V) {
      debug(l, r, idx, lca);

      while (cur_l > l)
         change(--cur_l);
      while (cur_r < r)
         change(++cur_r);
      while (cur_l < l)
         change(cur_l++);
      while (cur_r > r)
         change(cur_r--);

      if (lca != NO_LCA)
         change(lca);

      odp[idx] = res;

      if (lca != NO_LCA)
         change(lca);
   }
}

void input() {
   cin >> n;
   vector<int> A(n), B(n);
   rep(i, n) cin >> A[i];
   rep(i, n) cin >> B[i];
   indexed_set S(all(B));
   rep(i, n) node[i] = {A[i], S.order_of_key(B[i])};
   G.resize(n);

   rep(i, n - 1) {
      int a, b;
      cin >> a >> b;
      G[--a].push_back(--b);
      G[b].push_back(a);
   }
}

int32_t main() {
   _upgrade;
   input();
   LCA L(G);
   int c = 0;
   dfs(0, c);

   int q;
   cin >> q;
   vector<Query> V(q);

   rep(i, q) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      if (st[u] > st[v])
         swap(u, v);
      auto p = L.lca(u, v);
      debug(u, v, p);
      if (p == u)
         V[i] = {st[u], st[v], i, NO_LCA};
      else
         V[i] = {en[u], st[v], i, st[p]};
   }
   debug(S);
   solve(V);
   rep(i, q) cout << odp[i] << endl;
}