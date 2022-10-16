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
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
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

const int MAXN = 32;

const int N = 1000;

vector<int> G[N];
bool vis[N][N];

void dfs(int x, bool vis[N]) {
   vis[x] = true;
   for (int y : G[x])
      if (!vis[y])
         dfs(y, vis);
}

void init() {
   for (int i = 1; i < N; i++)
      for (int j = 0; j + i < N; j++)
         if ((j & i) == j)
            G[i].push_back(i + j);
   for (int i = 1; i < N; i++)
      dfs(i, vis[i]);
}

bool get(int x, int i) { return x & (1ll << i); }

bool solve(int u, int v) {
   // debug(u, v);
   if (u > v)
      return false;
   int p = 0;
   int q = 0;

   rep(i, MAXN) {
      p += get(u, i);
      q += get(v, i);
      if (q > p)
         return false;
   }

   return true;
}

void solve() {
   int u, v;
   cin >> u >> v;
   bool OK = solve(u, v);
   if (OK) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
}

void check() {
   init();
   rep(i, N - 1) rep(j, N - 1) {

      if (!vis[i + 1][j + 1] == solve(i + 1, j + 1)) {
         debug(i + 1, j + 1);
         debug(solve(i + 1, j + 1));
         debug(vis[i + 1][j + 1]);
         debug("NIEOK");
         exit(0);
      }
   }
}

int32_t main() {
   _upgrade;
   // check();
   int Z;
   cin >> Z;
   while (Z--) {
      solve();
   }

   //  rep(i, 20) rep(j, 20) { solve(i + 1, j + 1); }
}