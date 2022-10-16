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

const int MAXN = 1e6;
int kapitan[MAXN];
int n, m, k;

void pre() { rep(i, n + 10) kapitan[i] = i; }

int ffind(int x) {
   if (kapitan[x] == x)
      return x;
   return kapitan[x] = ffind(kapitan[x]);
}

bool unia(int a, int b) {
   int x = ffind(a);
   int y = ffind(b);
   kapitan[x] = y;
   return x != y;
}

pii solve(set<pair<int, pii>> &S) {
   pre();
   int cost = 0;
   for (auto s : S) {
      if (unia(s.nd.st, s.nd.nd))
         cost += s.st;
   }
   rep(i, n) if (ffind(i) != ffind(0)) return {0, -1};
   return {1, cost};
}

int32_t main() {
   int Z;
   cin >> Z;
   while (Z--) {
      cin >> n >> m >> k;

      set<pair<int, pii>> S1;
      set<pair<int, pii>> S2;
      int res = k + 100;

      rep(i, m) {
         int a, b, c;
         cin >> a >> b >> c;
         if (c > k) {
            S1.insert({c - k, {--a, --b}});
         } else {
            S1.insert({0, {--a, --b}});
            S2.insert({0, {a, b}});
         }
         res = min(res, abs(c - k));
      }
      auto p1 = solve(S2);
      auto p2 = solve(S1);
      debug(p1, p2, res);
      if (p1.st) {
         cout << res << endl;
         continue;
      }
      cout << p2.nd << endl;
   }
}