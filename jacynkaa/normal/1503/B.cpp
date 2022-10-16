#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
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

void wypisz(vector<pii> &Q, int x) {
   cout << x << " " << Q.back().st << " " << Q.back().nd << endl;
   Q.pop_back();
}

int32_t main() {
   int n;
   cin >> n;
   vector<pii> jed;
   vector<pii> dwa;

   rep(i, n) rep(j, n) {
      if ((i + j) % 2)
         jed.push_back({i + 1, j + 1});
      else
         dwa.push_back({i + 1, j + 1});
   }

   while (sz(jed) + sz(dwa)) {
      int a;
      cin >> a;
      if (sz(jed) == 0) {
         wypisz(dwa, a == 2 ? 3 : 2);
         continue;
      }
      if (sz(dwa) == 0) {
         wypisz(jed, a == 1 ? 3 : 1);
         continue;
      }
      if (a != 2)
         wypisz(dwa, 2);
      else
         wypisz(jed, 1);
   }
}