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
#define debug(...)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
   {}
#endif

int n;
const int inf = 1e9;

void app1(vector<int> &X, int &r) {
   r++;
   rep(i, n) swap(X[2 * i], X[2 * i + 1]);
}
void app2(vector<int> &X, int &r) {
   r++;
   rep(i, n) swap(X[i], X[n + i]);
}

int32_t main() {
   _upgrade;
   cin >> n;

   vector<int> X(2 * n);
   rep(i, 2 * n) cin >> X[i];
   debug(X);

   auto cp = X;

   int r = 0;
   int res = inf;

   if (is_sorted(all(X))) {
      cout << 0 << endl;
      exit(0);
   }

   while (true) {

      app1(X, r);

      if (X == cp)
         break;

      if (is_sorted(all(X))) {
         res = min(res, r);
         break;
      }

      app2(X, r);
      if (X == cp)
         break;

      if (is_sorted(all(X))) {
         res = min(res, r);
         break;
      }
   }

   X = cp;
   r = 0;

   while (true) {
      app2(X, r);
      if (X == cp)
         break;
      if (is_sorted(all(X))) {
         res = min(res, r);
         break;
      }

      app1(X, r);
      if (X == cp)
         break;
      if (is_sorted(all(X))) {
         res = min(res, r);
         break;
      }
   }
   cout << (res == inf ? -1 : res) << endl;
}