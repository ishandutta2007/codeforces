#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
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
#define int long long

int n, k, q;
const int MAXN = 5002;
const int MOD = 1e9 + 7;

int L[MAXN][MAXN];
int cnt[MAXN];
int X[MAXN];

void pre() {
   for (int i = 1; i <= n; i++)
      L[0][i] = 1;

   for (int j = 1; j < MAXN; j++)
      for (int i = 1; i <= n; i++)
         L[j][i] = (L[j - 1][i - 1] + L[j - 1][i + 1]) % MOD;

   for (int i = 1; i <= n; i++) {
      for (int l = 0; l <= k; l++)
         cnt[i] = (cnt[i] + L[l][i] * L[k - l][i]) % MOD;
   }
}

int32_t main() {
   _upgrade;
   cin >> n >> k >> q;
   pre();

   for (int i = 1; i <= n; i++)
      cin >> X[i];

   int res = 0;
   for (int i = 1; i <= n; i++)
      res = (res + cnt[i] * X[i]) % MOD;

   while (q--) {
      int a, b;
      cin >> a >> b;
      res -= cnt[a] * X[a];
      X[a] = b;
      res += cnt[a] * X[a];
      res += MOD * MOD;
      res %= MOD;

      cout << res << endl;
   }
}