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
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

int kapitan[MAXN];
bool OK[MAXN];
int POW[MAXN];

int fiind(int x) {
   if (kapitan[x] == x)
      return x;
   return kapitan[x] = fiind(kapitan[x]);
}

bool unia(int a, int b) {
   int x = fiind(a);
   int y = fiind(b);
   if (x != y && (OK[x] == false || OK[y] == false)) {
      kapitan[y] = x;
      OK[x] = (OK[x] || OK[y]);
      return true;
   }
   return false;
}

bool setOK(int a) {
   int x = fiind(a);
   if (OK[x])
      return false;
   return OK[x] = true;
}

void pre() {
   rep(i, MAXN) {
      POW[i] = i == 0 ? 1 : (2 * POW[i - 1]) % MOD;
      kapitan[i] = i;
      OK[i] = false;
   }
}

int32_t main() {
   _upgrade;
   pre();
   int n, m;
   cin >> n >> m;
   vector<int> X;
   int res = 1;
   rep(i, n) {
      int k;
      cin >> k;
      if (k == 1) {
         int a;
         cin >> a;
         if (setOK(a)) {
            X.push_back(i);
            res = (res * 2) % MOD;
         }
      } else {
         int a, b;
         cin >> a >> b;
         if (unia(a, b)) {
            X.push_back(i);
            res = (res * 2) % MOD;
         }
      }
   }
   cout << res << " " << sz(X) << endl;
   for (int x : X)
      cout << x + 1 << " ";
   cout << endl;
}