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

int n;
const int MAXM = 35;

int find(int x) {
   if (x == 0)
      return 0;
   for (int i = 30; i >= 0; i--)
      if (x & (1ll << i))
         return i + 1;
}

int isGood(vector<int> A) {
   if (sz(A) <= 1)
      return 0;

   vector<vector<int>> X(MAXM);

   for (int a : A) {
      X[find(a)].push_back(a);
   }

   int ile = sz(A);
   int cnt = 0;
   int res = sz(A);

   // debug(A, X, ile, cnt, res);

   for (int i = MAXM - 1; i >= 0; i--) {
      if (sz(X[i]) == 0)
         continue;
      int pot = max(0ll, i - 1);
      auto &V = X[i];
      for (auto &v : V)
         v ^= (1 << pot);
      ile -= sz(V);
      res = min(res, cnt + max(ile - 1, 0ll) + isGood(V));
      cnt += (sz(V) - 1);
   }
   return res;
}

int32_t main() {
   int n;
   cin >> n;
   vector<int> A(n);
   rep(i, n) cin >> A[i];
   int val = isGood(A);
   cout << val << endl;
}