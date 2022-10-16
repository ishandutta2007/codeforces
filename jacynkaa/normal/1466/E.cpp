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

const int MAXS = 60;
const long long MOD = 1e9 + 7;

int C[MAXS][MAXS];
int D[MAXS];
bool cur[MAXS];

void dzia(long long x) {
   for (int i = 0; i < MAXS; i++) {
      cur[i] = (x & (1ll << i)) ? true : false;
      D[i] += cur[i];
   }
   rep(i, MAXS) rep(j, MAXS) { C[i][j] += cur[i] && cur[j]; }
}

void pre(vector<long long> &X) {
   for (auto x : X)
      dzia(x);
}

void clear() {
   rep(i, MAXS) D[i] = 0;
   rep(i, MAXS) cur[i] = false;
   rep(i, MAXS) rep(j, MAXS) C[i][j] = 0;
}

int32_t main() {
   _upgrade;
   int Z;
   cin >> Z;
   while (Z--) {
      clear();

      int n;
      cin >> n;
      vector<long long> X(n);
      rep(i, n) cin >> X[i];
      // rep(i, n) X[i] = i % 2 ? (1ll << MAXS) - 1 : rand();
      pre(X);
      long long res = 0;
      rep(i, MAXS) rep(j, MAXS) {
         long long mnoznik = (((1ll << i) % MOD) * ((1ll << j) % MOD)) % MOD;
         long long val1 = (long long)(D[i]) * (long long)C[i][j] * n;
         long long val2 = (long long)(D[i]) * (long long)(D[i] - C[i][j]) * D[j];
         val1 %= MOD;
         val2 %= MOD;

         res = (res + (mnoznik * (val1 + val2))) % MOD;
         // if (val1 + val2 != 0)
         //    debug(i, j, mnoznik, val1, val2, zysk);
      }
      cout << res << endl;
   }
}