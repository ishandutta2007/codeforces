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
const int MAX = 54;

string S;
int T;

int get(char c) { return c - 'a'; }

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      bool OK = true;
      vector<int> X(5);
      vector<int> C(3);
      rep(i, 3) cin >> C[i];
      rep(i, 5) cin >> X[i];
      rep(i, 3) {
         if (C[i] < X[i]) {
            debug(i);
            OK = false;
         }
         C[i] -= X[i];
      }
      if (!OK) {
         cout << "NO" << endl;
         continue;
      }
      rep(i, 2) { X[i + 3] = max(0ll, X[i + 3] - C[i]); }

      if (C[2] >= X[4] + X[3]) {
         cout << "YES" << endl;
      } else {
         cout << "NO" << endl;
      }
   }
}