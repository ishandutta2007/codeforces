#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")
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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
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

struct LazySegmentTree { // drzewo przedzia-przedzia (add,min)

   struct content {
      int mod, mini; // modyfikator w wezle i mini biorac pod uwage tylko modyfikatory tylko pod wezlem
   };

   vector<content> C;
   int size;

   LazySegmentTree(int x) {
      size = x, C.resize(size * 2);
      debug(x, size);
   } // drzewo przedzialowe dla zakresu [0,x),

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

   // int query(int p, int q, int l, int r, int wezel = 1) { // max[p,q]
   //    if (p > q)
   //       return inf; // UWAGA

   //    if (p == l && q == r)
   //       return C[wezel].mini;

   //    return min(query(p, min(r1, q), l, r1, 2 * wezel), query(max(l2, p), q, l2, r, 2 * wezel + 1)) + C[wezel].mod;
   // }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
   int query(int p, int q) { return C[1].mini; }
};

struct SegmentTree { // drzewo przedzia-przedzia (add,sum)

   struct content {
      int mod;
      int sum;
   };

   vector<content> C;
   int size;

   SegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2); } // drzewo przedzialowe dla zakresu [0,x),

   void add(int p, int q, int val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel].mod += val;
         C[wezel].sum += (q - p + 1) * val;
         return;
      }

      add(p, min(r1, q), val, l, r1, 2 * wezel);
      add(max(l2, p), q, val, l2, r, 2 * wezel + 1);

      C[wezel].sum = C[2 * wezel].sum + C[2 * wezel + 1].sum + C[wezel].mod * (r - l + 1);
   }

   int query(int p, int q, int l, int r, int wezel = 1) { // suma na przedzial [p,q]
      if (p > q)
         return 0;

      if (p == l && q == r)
         return C[wezel].sum;

      return query(p, min(r1, q), l, r1, 2 * wezel) + query(max(l2, p), q, l2, r, 2 * wezel + 1) + C[wezel].mod * (q - p + 1);
   }

   void add(int p, int q, int val) { add(p, q, val, 0, size - 1); }
   int query(int p, int q) { return query(p, q, 0, size - 1); }
};

#define SUB 0
#define QU 1
#define ADD 2

#define tpl tuple<int, int, int>

struct FT {
   vector<ll> s;
   FT(int n) : s(n) {}
   void update(int pos, ll dif) { // a[pos] += dif
      for (; pos < sz(s); pos |= pos + 1)
         s[pos] += dif;
   }
   ll query(int pos) { // sum of values in [0, pos)
      ll res = 0;
      for (; pos > 0; pos &= pos - 1)
         res += s[pos - 1];
      return res;
   }
   int lower_bound(ll sum) { // min pos st sum of [0, pos] >= sum
      // Returns n if no sum is >= sum, or -1 if empty sum is.
      if (sum <= 0)
         return -1;
      int pos = 0;
      for (int pw = 1 << 25; pw; pw >>= 1) {
         if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
            pos += pw, sum -= s[pos - 1];
      }
      return pos;
   }
};

void solve() {
   int n, m;
   // n = 1e6;
   // m = 1e6;
   cin >> n >> m;
   int l = (1 << (32 - __builtin_clz(n + 2)));

   LazySegmentTree ST(l);

   int res = 0;
   int cnt = 1;
   vector<tpl> Q;
   vector<pii> A;

   rep(i, n) {
      int a;
      cin >> a;
      A.push_back({-a, -i});
      ST.add(i + 1, l - 1, 1);

      Q.push_back({a, SUB, i});
      Q.push_back({a, ADD, i});
   }

   FT F(l);
   sort(all(A));
   debug(A);
   for (auto [a, i] : A) {
      i = abs(i);
      res += F.query(i);
      F.update(i, 1);
   }

   debug(res);

   rep(i, m) {
      int b;
      cin >> b;
      Q.push_back({b, QU, -1});
   }

   sort(all(Q));

   for (auto [_, t, i] : Q) {
      if (t == SUB) {
         ST.add(i + 1, l - 1, -1);
      }
      if (t == ADD) {
         ST.add(0, i, 1);
      }
      if (t == QU) {
         res += ST.query(0, n);
      }
   }
   cout << res << endl;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      solve();
   }
}