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
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(12), cin.tie(0), cout.tie(0);
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

int n, w;

bool isOk(int a) { return a >= ((w + 1) / 2) && a <= w; }

vector<int> solve(vector<pii> X) {
   sort(all(X));
   int sum = 0;
   vector<int> res;
   for (pii x : X)
      if (isOk(x.st))
         return {x.nd};
   for (pii x : X) {
      sum += x.st;
      res.push_back(x.nd);
      if (isOk(sum))
         return res;
   }
   return {-1};
}

int32_t main() {
   int Z;
   cin >> Z;
   while (Z--) {
      cin >> n >> w;
      vector<pii> X(n);
      rep(i, n) {
         cin >> X[i].st;
         X[i].nd = i;
      }
      auto res = solve(X);
      sort(all(res));
      if (res[0] == -1) {
         cout << -1 << endl;
         continue;
      }

      cout << sz(res) << endl;
      for (auto a : res)
         cout << a + 1 << " ";
      cout << endl;
   }
}