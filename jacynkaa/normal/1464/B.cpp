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

string S;
int x, y;

int solve() {
   vector<int> Z(sz(S));
   vector<int> wynik1(sz(S));

   rep(i, sz(S)) {
      if (i == 0) {
         wynik1[i] = 0;
         if (S[i] != '1')
            Z[i]++;
         continue;
      }
      wynik1[i] = wynik1[i - 1];
      Z[i] = Z[i - 1];
      if (S[i] == '1') {
         wynik1[i] += Z[i] * x;
      } else {
         wynik1[i] += (i - Z[i]) * y;
         Z[i]++;
      }
   }

   vector<int> J(sz(S));
   vector<int> wynik2(sz(S));
   for (int i = sz(S) - 1; i >= 0; i--) {
      if (i == sz(S) - 1) {
         wynik2[i] = 0;
         if (S[i] != '0')
            J[i]++;
         continue;
      }

      wynik2[i] = wynik2[i + 1];
      J[i] = J[i + 1];

      if (S[i] == '0') {
         wynik2[i] += J[i] * x;
      } else {
         wynik2[i] += (sz(S) - i - 1 - J[i]) * y;
         J[i]++;
      }
   }
   int result = min(wynik2[0], wynik1[sz(S) - 1]);

   // debug(wynik1, Z);
   //  debug(wynik2, J);

   rep(i, sz(S) - 1) {
      int Z1 = Z[i];
      int J1 = i + 1 - Z[i];
      int J2 = J[i + 1];
      int Z2 = sz(S) - Z1 - J1 - J2;
      // debug(i, Z1, J1, Z2, J2);
      // debug(wynik1[i] + wynik2[i + 1] + Z1 * J2 * x + Z2 * J1 * y);
      result = min(result, wynik1[i] + wynik2[i + 1] + Z1 * J2 * x + Z2 * J1 * y);
   }
   return result;
}

int32_t main() {
   _upgrade;

   cin >> S;
   cin >> x >> y;

   int wynik = solve();
   reverse(all(S));
   swap(x, y);
   wynik = min(wynik, solve());
   cout << wynik << endl;
}