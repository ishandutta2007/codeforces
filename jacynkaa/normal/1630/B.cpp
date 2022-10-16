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

int n, k;

pii best(pii a, pii b) { return a.nd - a.st < b.nd - b.st ? a : b; }

int32_t main() {
   _upgrade;

   int Z;
   cin >> Z;

   while (Z--) {
      cin >> n >> k;
      vector<int> A(n);
      vector<int> T(n);
      rep(i, n) {
         cin >> A[i];
         T[--A[i]]++;
      }
      pii res = {0, n - 1};

      int y = -1;
      int sum = -n;
      rep(x, n) {
         while (y != n - 1 && sum < k)
            sum += 2 * T[++y];

         if (sum >= k) {
            debug(sum, mp(x, y));
            res = best(res, {x, y});
         }
         
         sum -= 2 * T[x];
      }

      auto [xx, yy] = res;

      cout << xx + 1 << " " << yy + 1 << endl;
      vector<pii> X;

      int l = 0;
      sum = 0;

      rep(i, n) {
         if (sz(X) == k - 1)
            break;
         if (A[i] < xx || A[i] > yy)
            sum--;
         else
            sum++;
         if (sum > 0) {
            X.push_back({l + 1, i + 1});
            sum = 0;
            l = i + 1;
         }
      }
      X.push_back({l + 1, n});
      for (auto [a, b] : X)
         cout << a << " " << b << endl;
   }
}