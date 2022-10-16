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

bool isValid(string S) {
   int x = 0;
   for (auto c : S) {
      if (c == '(')
         x++;
      else
         x--;
      if (x < 0)
         return false;
   }
   return true;
}
int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      int n;
      cin >> n;
      string S;
      cin >> S;
      if (count(all(S), '1') % 2 == 1) {
         cout << "NO\n";
         continue;
      }
      string res1, res2;
      int zero = count(all(S), '1') / 2;
      int k = 0;
      for (auto c : S) {
         if (c == '1') {
            if (zero > 0) {
               res1.push_back('(');
               res2.push_back('(');
            } else {
               res1.push_back(')');
               res2.push_back(')');
            }
            zero--;
         } else {
            if (k % 2) {
               res1.push_back(')');
               res2.push_back('(');
            } else {
               res1.push_back('(');
               res2.push_back(')');
            }
            k++;
         }
      }
      debug(res1, res2);
      if (isValid(res1) and isValid(res2)) {
         cout << "YES\n";
         cout << res1 << endl << res2 << endl;
      } else {
         cout << "NO\n";
      }
   }
}