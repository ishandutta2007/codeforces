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

pii apply(pii pos, char c) {
   if (c == 'L') {
      return {pos.st - 1, pos.nd};
   }
   if (c == 'R') {
      return {pos.st + 1, pos.nd};
   }
   if (c == 'U') {
      return {pos.st, pos.nd + 1};
   }
   if (c == 'D') {
      return {pos.st, pos.nd - 1};
   }
}

pii apply(pii pos, char c, pii obs) {
   auto next_pos = apply(pos, c);
   return next_pos == obs ? pos : next_pos;
}

bool solve(string S, pii obs) {
   pii pos = {0, 0};
   for (char c : S) {
      pos = apply(pos, c, obs);
   }
   return pos == mp(0, 0);
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      string S;
      cin >> S;
      pii pos = {0, 0};
      bool znalazlem = false;
      for (char c : S) {
         pos = apply(pos, c);
         if (pos != mp(0, 0) && solve(S, pos)) {
            cout << pos.st << " " << pos.nd << endl;
            znalazlem = true;
            break;
         }
      }
      if (!znalazlem) {
         cout << 0 << " " << 0 << endl;
      }
   }
}