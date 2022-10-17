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

#define r1 ((l + r) / 2)   // ulatwia branie srodka przedzialu
#define l2 (r1 + 1)        // same
const int inf = 1LL << 30; // ustawic w zaleznosci

struct LazySegmentTree { // drzewo przedzial-przedzial (add,min)

   struct content {
      int mod, mini; // modyfikator w wezle i mini biorac pod uwage tylko modyfikatory tylko pod wezlem
   };

   vector<content> C;
   int size;
   LazySegmentTree() {} // drzewo przedzialowe dla zakresu [0,x),

   LazySegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2); } // drzewo przedzialowe dla zakresu [0,x),

   inline void push(int wezel) {
      C[2 * wezel].mod += C[wezel].mod;
      C[2 * wezel + 1].mod += C[wezel].mod;
      C[2 * wezel].mini += C[wezel].mod;
      C[2 * wezel + 1].mini += C[wezel].mod;
      C[wezel].mod = 0;
   }
   inline void update(int wezel) { C[wezel].mini = min(C[2 * wezel + 1].mini, C[2 * wezel].mini) + C[wezel].mod; }

   void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel].mod += val;
         C[wezel].mini += val;
         return;
      }
      push(wezel);

      add(p, min(r1, q), val, l, r1, 2 * wezel);
      add(max(l2, p), q, val, l2, r, 2 * wezel + 1);

      update(wezel);
   }

   int query(int p, int q, int l, int r, int wezel = 1) { // max[p,q]
      if (p > q)
         return inf; // UWAGA

      if (p == l && q == r)
         return C[wezel].mini;

      return min(query(p, min(r1, q), l, r1, 2 * wezel), query(max(l2, p), q, l2, r, 2 * wezel + 1)) + C[wezel].mod;
   }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
   int query(int p, int q) { return query(p, q, 0, size - 1); }
};

int n;

LazySegmentTree U, D;
vector<pii> UU, DD;

void clear() {
   U = LazySegmentTree(n + 1);
   D = U;
   UU.clear();
   DD.clear();
}

int add(int a, int i, vector<pii> &UU, LazySegmentTree &U, LazySegmentTree &D, bool t) {
   while (sz(UU) && (UU.back().st < a) == t) {
      auto [_, i] = UU.back();
      U.add(i, i, inf);
      UU.pop_back();
   }

   int l = sz(UU) ? UU.back().nd + 1 : 0;
   int res = D.query(l, i - 1);
   UU.push_back({a, i});

   return res;
}

int add_d(int a, int i) { return add(a, i, DD, D, U, false); }
int add_u(int a, int i) { return add(a, i, UU, U, D, true); }

void solve() {
   cin >> n;
   clear();
   int wynik = 0;
   rep(i, n) {
      int a;
      cin >> a;
      int res = min(add_d(a, i), add_u(a, i)) + 1;

      if (i == 0)
         res = 0;

      wynik = res;
      D.add(i, i, res);
      U.add(i, i, res);
      debug(DD, UU);
   }
   cout << wynik << endl;
}

int32_t main() {
   _upgrade;

   int Z;
   cin >> Z;
   while (Z--)
      solve();
}