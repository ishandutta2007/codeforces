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
   int n;

   cin >> n >> T;
   cin >> S;

   T -= 1 << get(S.back());
   S.pop_back();

   T += 1 << get(S.back());
   S.pop_back();

   vector<int> X(MAX);
   for (char c : S) {
      X[get(c) + 1]++;
      T += 1 << get(c);
   }

   // debug(X, T, S);

   if (T < 0) {
      cout << "No" << endl;
      exit(0);
   }

   int k = 0;
   rep(j, MAX) {
      int r = (T & (1ll << j)) ? 1 : 0;
      k += X[j];
      k -= r;
      if (k < 0) {
         cout << "No" << endl;
         exit(0);
      }
      k /= 2;
   }
   cout << "Yes\n";
}