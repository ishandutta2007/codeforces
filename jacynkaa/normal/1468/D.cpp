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
//#define int long long

bool check(vector<int> &S, int s, int t) {
   for (int i = s - 1; i >= 0; i--) {
      if (S[i] > t)
         return false;
      t--;
   }
   return true;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      int n, m, a, b;
      cin >> n >> m >> a >> b;
      if (a > b) {
         a = n - a + 1;
         b = n - b + 1;
      }
      int k = b - a - 1;
      int t = b - 2;

      debug(k, t);
      vector<int> S(m);
      rep(i, m) cin >> S[i];
      sort(all(S));

      int p = 0;
      int q = min(k, m);
      while (p != q) {
         int s = (p + q + 1) / 2;
         if (check(S, s, t))
            p = s;
         else {
            q = s - 1;
         }
      }
      cout << p << endl;
   }
}