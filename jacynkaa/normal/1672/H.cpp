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

   typedef pii tpl;

   vector<tpl> C;
   int size;
   pii combine(tpl a, tpl b) { return {a.st + b.st, a.nd + b.nd}; }

   SegmentTree(int x, vector<pii> R) {
      size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2);
      rep(i, sz(R)) C[i + size] = R[i];
      for (int i = size - 1; i > 0; i--)
         C[i] = combine(C[2 * i], C[2 * i + 1]);
   } // drzewo przedzialowe dla zakresu [0,x),

   // void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
   //    if (p > q)
   //       return;

   //    if (p == l && q == r) {
   //       r
   //    }

   //    add(p, min(r1, q), val, l, r1, 2 * wezel);
   //    add(max(l2, p), q, val, l2, r, 2 * wezel + 1);

   //    C[wezel].sum = C[2 * wezel].sum + C[2 * wezel + 1].sum + C[wezel].mod * (r - l + 1);
   // }

   pii query(int p, int q, int l, int r, int wezel = 1) { // suma na przedzial [p,q]
      if (p > q)
         return {0, 0};

      if (p == l && q == r)
         return C[wezel];

      return combine(query(p, min(r1, q), l, r1, 2 * wezel), query(max(l2, p), q, l2, r, 2 * wezel + 1));
   }

   pii query(int p, int q) { return query(p, q, 0, size - 1); }
};

void solve() {
   int n, q;
   cin >> n >> q;
   string S;
   cin >> S;
   vector<pii> P(n);
   rep(i, n) if (S[i] == S[i + 1]) {
      if (S[i + 1] == '0')
         P[i + 1].st++;
      else
         P[i + 1].nd++;
   }
   SegmentTree ST(n + 1, P);
   while (q--) {
      int l, r;
      cin >> l >> r;
      auto [a, b] = ST.query(l, r - 1);
      cout << max(a, b) + 1 << endl;
   }
}

int32_t main() {
   _upgrade;
   int Z;
   // cin >> Z;
   Z = 1;
   while (Z--)
      solve();
}