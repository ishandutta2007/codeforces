#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;

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
#define int long long

bool visited[(int)1e6 + 99];

pii get(pii X1, pii X2) {
   int x = X1.st - X2.st;
   int y = X1.nd - X2.nd;
   if (x == 0) {
      return {0, y > 0 ? 1 : -1};
   }
   if (y == 0) {
      return {x > 0 ? 1 : -1, 0};
   }
   return {x / __gcd(abs(x), abs(y)), y / __gcd(abs(x), abs(y))};
}
int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      int n;
      cin >> n;
      map<pii, int> M;
      rep(i, n) {
         pii x1, x2;
         cin >> x1.st >> x1.nd >> x2.st >> x2.nd;
         auto t = get(x1, x2);
         // debug(x1, x2, t);
         M[t]++;
      }
      int res = 0;
      for (auto m : M) {
         pii mp = {-m.st.st, -m.st.nd};
         auto ptr = M.find(mp);
         if (ptr != M.end()) {
            res += ptr->nd * m.nd;
         }
      }
      cout << res / 2 << endl;
   }
}