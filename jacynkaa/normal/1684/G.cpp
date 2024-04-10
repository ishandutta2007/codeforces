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

typedef vector<int> vi;

namespace Match {
   bool dfs(int a, int L, vector<vi> &g, vi &btoa, vi &A, vi &B) {
      if (A[a] != L)
         return 0;
      A[a] = -1;
      for (int b : g[a])
         if (B[b] == L + 1) {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
               return btoa[b] = a, 1;
         }
      return 0;
   }

   int hopcroftKarp(vector<vi> &g, vi &btoa) {
      int res = 0;
      vi A(g.size()), B(btoa.size()), cur, next;
      for (;;) {
         fill(all(A), 0);
         fill(all(B), 0);
         /// Find the starting nodes for BFS (i.e. layer 0).
         cur.clear();
         for (int a : btoa)
            if (a != -1)
               A[a] = -1;
         rep(a, sz(g)) if (A[a] == 0) cur.push_back(a);
         /// Find all layers using bfs.
         for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur)
               for (int b : g[a]) {
                  if (btoa[b] == -1) {
                     B[b] = lay;
                     islast = 1;
                  } else if (btoa[b] != a && !B[b]) {
                     B[b] = lay;
                     next.push_back(btoa[b]);
                  }
               }
            if (islast)
               break;
            if (next.empty())
               return res;
            for (int a : next)
               A[a] = lay;
            cur.swap(next);
         }
         /// Use DFS to scan for augmenting paths.
         rep(a, sz(g)) res += dfs(a, 0, g, btoa, A, B);
      }
   }
} // namespace Match

int get(int a, int b) { return ((b / a) + 1) * a; }
bool ok(int a, int b, int m) {
   debug(a, b, m, get(a, b));
   return get(a, b) + b <= m;
}

int Euclid(int a, int b, vector<int> &T) {
   if (a < b)
      swap(a, b);

   if (b == 0)
      return a;

   int r = a % b;

   if (r > 0)
      T.push_back(r);

   return Euclid(b, r, T);
}

void solve() {
   int n, m;
   cin >> n >> m;
   vector<int> L, R;

   rep(i, n) {
      int a;
      cin >> a;
      if (3 * a <= m)
         R.push_back(a);
      else
         L.push_back(a);
   }

   vector<vector<int>> G(sz(L));
   rep(i, sz(L)) rep(j, sz(R)) if ((L[i] % R[j] == 0) && ok(R[j], L[i], m)) G[i].push_back(j);

   debug(L, R, G);

   vector<int> btoa(sz(R), -1);
   int res = Match::hopcroftKarp(G, btoa);

   debug(btoa);

   if (res != sz(L)) {
      cout << -1 << endl;
      return;
   }

   vector<pii> ress;
   rep(i, sz(R)) {
      if (btoa[i] == -1)
         ress.push_back({2 * R[i], 3 * R[i]});

      else {
         int a = R[i];
         int b = L[btoa[i]];
         int A = get(a, b);
         ress.push_back({A + b, A});
      }
   }

   cout << sz(R) << endl;
   for (auto [a, b] : ress)
      cout << a << " " << b << endl;

   vector<int> T;
   for (auto [a, b] : ress)
      Euclid(a, b, T);
   debug(T);
}

int32_t main() {
   _upgrade;
   int Z;
   Z = 1;
   while (Z--)
      solve();
}