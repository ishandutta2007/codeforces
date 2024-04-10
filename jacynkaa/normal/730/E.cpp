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

typedef tuple<int, int, int> tpl;

typedef tree<tpl, null_type, less<tpl>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

int32_t main() {
   _upgrade;
   int n;
   cin >> n;
   indexed_set S;

   vector<tpl> P;
   rep(i, n) {
      int a, b;
      cin >> a >> b;
      P.push_back({a, -i, b});
      S.insert(P.back());
   }

   sort(all(P));
   int res = 0;
   for (auto [a, i, b] : P)
      if (b > 0) {
         int x = S.order_of_key({a, i, b});
         int y = S.order_of_key({a + b, i, b});
         res += abs(x - y) - 1;
         S.erase({a, i, b});
         S.insert({a + b, i, b});
         debug(res);
      }
   sort(all(P), greater<tpl>());

   for (auto [a, i, b] : P)
      if (b < 0) {
         int x = S.order_of_key({a, i, b});
         int y = S.order_of_key({a + b, i, b});
         res += abs(x - y);
         S.erase({a, i, b});
         S.insert({a + b, i, b});
         debug(res);
      }
   cout << res << endl;
}