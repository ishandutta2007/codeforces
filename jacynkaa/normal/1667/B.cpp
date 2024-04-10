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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

const int inf = 1e18;

#define r1 ((l + r) / 2) // ulatwia branie srodka przedzialu
#define l2 (r1 + 1)

struct SegmentTree { // drzewo przedzial-przedzial (add,sum)

   vector<int> C;
   int size;

   SegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2, -inf); } // drzewo przedzialowe dla zakresu [0,x),

   void update(int wezel) { C[wezel] = max(C[wezel * 2], C[wezel * 2 + 1]); }

   void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel] = max(C[wezel], val);
         return;
      }

      add(p, min(r1, q), val, l, r1, 2 * wezel);
      add(max(l2, p), q, val, l2, r, 2 * wezel + 1);
      update(wezel);
   }

   int query(int p, int q, int l, int r, int wezel = 1) { // suma na przedzial [p,q]
      if (p > q)
         return -inf;

      if (p == l && q == r) {
         // debug(C[wezel]);
         return C[wezel];
      }

      return max(query(p, min(r1, q), l, r1, 2 * wezel), query(max(l2, p), q, l2, r, 2 * wezel + 1));
   }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
   int query(int p, int q) { return query(p, q, 0, size - 1); }
};

int get(int val, indexed_set &S) { return S.order_of_key(val); }

void solve() {
   int n;
   cin >> n;

   vector<int> X(n);
   rep(i, n) cin >> X[i];
   vector<int> S(n + 1);
   rep(i, n) S[i + 1] = S[i] + X[i];

   indexed_set IS(all(S));
   debug(IS);

   const int N = n + 3;

   SegmentTree S1(N + 2), S2(N + 2);
   map<int, int> M;
   for (auto s : S)
      M[get(s, IS)] = -inf;

   int wynik = 0;
   for (int i = 0; i <= n; i++) {
      int idx = get(S[i], IS);
      debug(idx);
      int A = S1.query(0, idx - 1) + i;
      int B = S2.query(idx + 1, N + 1) - i;
      int C = M[idx];
      debug(A, B, C);
      int res = max({A, B, C});
      if (i == 0)
         res = 0;
      debug(res);
      M[idx] = res;
      S1.add(idx, idx, res - i);
      S2.add(idx, idx, res + i);
      wynik = res;
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