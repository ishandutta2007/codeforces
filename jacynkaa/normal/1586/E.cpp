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

const int MAXN = 3e5 + 99;

vector<int> G[MAXN];
vector<int> T[MAXN];
bool vis[MAXN];

void dfs1(int x) {
   vis[x] = true;

   for (int y : G[x])
      if (!vis[y]) {
         T[x].push_back(y);
         T[y].push_back(x);
         dfs1(y);
      }
}

vector<int> P;
bool find_path(int x, int target, int p = -1) {
   P.push_back(x);
   // debug(P);
   if (x == target)
      return true;
   for (int y : T[x]) {
      if (p != y && find_path(y, target, x))
         return true;
   }

   assert(P.back() == x);
   P.pop_back();
   return false;
}

int32_t main() {
   _upgrade;
   int n, m;
   cin >> n >> m;
   rep(i, m) {
      int a, b;
      cin >> a >> b;
      G[--a].push_back(--b);
      G[b].push_back(a);
   }

   dfs1(0);
   int q;
   cin >> q;
   map<int, int> M;
   vector<vector<int>> res;

   rep(i, q) {
      int a, b;
      cin >> a >> b;
      M[--a]++;
      M[--b]++;
      P.clear();
      find_path(a, b);
      res.push_back(P);
   }
   // exit(0);

   int cnt = 0;
   for (auto [_, a] : M)
      cnt += (a % 2);
   assert(cnt % 2 == 0);

   if (cnt == 0) {
      cout << "YES\n";
      for (auto V : res) {
         cout << sz(V) << endl;
         for (int v : V)
            cout << v + 1 << " ";
         cout << endl;
      }
   } else {
      cout << "NO\n";
      cout << cnt / 2 << endl;
   }
}