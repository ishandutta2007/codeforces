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
const int inf = 1e9;
const pii emp = {inf, inf};

struct SegmentTree { // drzewo przedzia-przedzia (add,sum)

   vector<pii> C;
   int size;

   SegmentTree(int x) { size = (1 << (32 - __builtin_clz(x))), C.resize(size * 2, emp); } // drzewo przedzialowe dla zakresu [0,x),

   void add(int p, int q, pii val, int l, int r, int wezel = 1) { // dodaje val do przedzialu [p,q]
      if (p > q)
         return;

      if (p == l && q == r) {
         C[wezel] = min(C[wezel], val);
         return;
      }

      add(p, min(r1, q), val, l, r1, 2 * wezel);
      add(max(l2, p), q, val, l2, r, 2 * wezel + 1);
   }

   void add(int p, int q, pii val) { add(p, q, val, 0, size - 1); }
   pii query(int p) {
      pii res = emp;
      p += size;
      while (p > 0) {
         res = min(res, C[p]);
         p = p / 2;
      }
      return res;
   }
};

int32_t main() {
   _upgrade;
   int n;
   cin >> n;
   vector<int> A(n);
   vector<int> B(n);

   rep(i, n) cin >> A[i];
   rep(i, n) cin >> B[i];
   SegmentTree S(n + 2);

   S.add(n, n, {0, -1});

   for (int i = n; i > 0; i--) {
      int l = S.query(i).st;
      if (l != inf) {
         int k = i + B[i - 1];
         S.add(k - A[k - 1], k, {l + 1, i});
      }
   }

   auto r = S.query(0);
   debug(r);
   cout << (r.st == inf ? -1 : r.st) << endl;

   vector<int> res = {0};
   debug(res);
   if (r.st != inf)
      while (r.st != 0) {
         res.push_back(r.nd);
         r = S.query(r.nd);
      }
   debug(res);
   res.pop_back();
   reverse(all(res));
   for (auto t : res)
      cout << t << " ";
   cout << endl;
}