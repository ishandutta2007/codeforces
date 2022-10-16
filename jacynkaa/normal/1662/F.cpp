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

#define r1 ((l + r) / 2) // ulatwia branie srodka przedzialu
#define l2 (r1 + 1)

struct SegmentTree { // drzewo przedzial-przedzial (add,sum)

   vector<set<int>> C;
   int size;

   SegmentTree(int x) {
      size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2);
      // rep(i, sz(X)) C[i + size] = X[i];
      // for (int i = size - 1; i > 0; i--) {
      //    C[i] = C[2 * i];
      //    for (int x : C[2 * i + 1])
      //       C[i].push_back(x);
      // }
      // for (auto &v : C)
      //    sort(all(v), greater<int>());
   } // drzewo przedzialowe dla zakresu [0,x),

   // void query(int p, int q, int l, int r, vector<int> &res, pii zakres, int wezel = 1) { // suma na przedzial [p,q]
   //    if (p > q)
   //       return;

   //    if (p == l && q == r) {
   //       auto [a, b] = zakres;
   //       auto itr1 = C[wezel].lower_bound(a);
   //       auto itr2 = C[wezel].upper_bound(b);
   //       res.insert(res.end(), itr1, itr2);
   //       C[wezel].erase(itr1, itr2);
   //       return;
   //    }

   //    query(p, min(r1, q), l, r1, res, zakres1, 2 * wezel);
   //    query(max(l2, p), q, l2, r, res, zakres, 2 * wezel + 1);
   // }

   void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel].insert(val);
         return;
      }

      add(p, min(r1, q), val, l, r1, 2 * wezel);
      add(max(l2, p), q, val, l2, r, 2 * wezel + 1);
   }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }

   vector<int> query(int p, pii zakres) {
      int wezel = p + size;
      vector<int> res;
      while (wezel > 0) {
         auto [a, b] = zakres;
         auto itr1 = C[wezel].lower_bound(a);
         auto itr2 = C[wezel].upper_bound(b);
         res.insert(res.end(), itr1, itr2);
         C[wezel].erase(itr1, itr2);
         wezel /= 2;
      }
      return res;
   }

   // vector<int> query(int p, int q, pii zakres) {
   //    vector<int> res;
   //    query(p, q, 0, size - 1, res, zakres);
   //    return res;
   // }
};

int solve() {
   int n, a, b;
   cin >> n >> a >> b;
   --a, --b;

   vector<int> P(n);
   SegmentTree S(n + 2);

   rep(i, n) {
      cin >> P[i];
      int p = max(0, i - P[i]);
      int q = min(n, P[i] + i);
      debug(i, p, q);
      S.add(p, q, i);
   }

   set<int> V;
   map<int, vector<int>> M;
   M[0] = {a};

   while (!M.empty()) {
      auto [d, v] = *M.begin();
      debug(d, v);
      M.erase(d);

      if (count(all(v), b))
         return d;

      for (auto i : v) {
         auto N = S.query(i, {i - P[i], i + P[i]});
         for (auto x : N)
            M[d + 1].push_back(x);
      }
   }

   assert(false);
}

void sol() {
   int res = solve();
   cout << res << endl;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      sol();
   }
}