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

// #define assert(X) 0

#define int long long
// typedef tuple<int, int, int> tpl;
int n, m;

const int MAXN = 1e6;

set<int> S;
set<pii> G[MAXN][2];

void dfs(int x, int r) {
   debug(x, r);
   assert(r == 1 || r == 0);
   assert(x >= 0);

   while ((sz(G[x][r])) + sz(G[x][r ^ 1])) {
      debug(x, r, G[x][0], G[x][1]);
      if (sz(G[x][r])) {
         auto [y, i] = *G[x][r].begin();
         G[x][r].erase({y, i});
         G[y][r].erase({x, -i});
         S.insert(i);
         dfs(y, r);
      } else {
         r ^= 1;
         assert(sz(G[x][r]));
         auto [y, i] = *G[x][r].begin();
         G[x][r].erase({y, i});
         G[y][r].erase({x, -i});
         S.insert(i);
         dfs(y, r);
      }
   }
}

void add(int a, int b, int c, int i) {
   i++;
   assert(a >= 0 && b >= 0);
   G[a][--c].insert({b, i});
   G[b][c].insert({a, -i});
}

typedef tuple<int, int, int> tpl;

void solve() {
   cin >> n >> m;
   vector<tpl> E;
   rep(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      add(a, b, c, i);
      E.push_back({a, b, c});
   }

   int cnt = m + 2;

   rep(i, n) {
      int a = sz(G[i + 1][0]) % 2;
      int b = sz(G[i + 1][1]) % 2;
      if (a + b == 1)
         add(0, i + 1, 1, cnt++);
   }
   rep(i, n + 1) dfs(i, 1);

   rep(i, n + 1) if ((sz(G[i][0]) + sz(G[i][1])) % 2 != 0) exit(0);

   map<int, int> M;

   rep(i, m) {
      auto id = i + 1;
      // assert(S.count(id) + S.count(-id));
      auto [a, b, c] = E[i];
      if (S.count((id)))
         M[a] += c, M[b] -= c;
      else
         M[a] -= c, M[b] += c;
   }

   int res = 0;
   for (auto [_, y] : M)
      if (abs(y) == 1)
         res++;

   cout << res << endl;

   rep(i, m) if (S.count(-i - 1)) cout << 2;
   else cout << 1;
   cout << endl;
}

int32_t main() {
   _upgrade;

   solve();
}