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

const int MAXN = 1e5;

int n, r;
vector<pii> X;

int32_t main() {
   _upgrade;
   cin >> n >> r;
   X.resize(n);

   rep(i, n) cin >> X[i].st;
   rep(i, n) cin >> X[i].nd;

   int cur_t = 0;
   int left = 0;
   vector<int> res;

   int k = 0;

   for (auto [l, t] : X) {
      int x = min(l, left);
      left -= x;
      l -= x;
      t -= x;
      cur_t += x;

      if (2 * l <= t) {
         cur_t += 2 * l;
         continue;
      }
      if (l > t) {
         cout << -1 << endl;
         exit(0);
      }

      int ile = 2 * l - t;

      cur_t += t;

      int u = ile % r;
      if (u == 0)
         u = r;

      left = r - u;

      int cnt = (ile + r - 1) / r;
      k += cnt;

      int f = cur_t - u;

      while (cnt-- && sz(res) <= MAXN + 2) {
         res.push_back(f);
         f -= r;
      }
   }
   sort(all(res));
   cout << k << endl;
   if (sz(res) <= MAXN) {
      for (int a : res)
         cout << a << " ";
   }
   cout << endl;
}