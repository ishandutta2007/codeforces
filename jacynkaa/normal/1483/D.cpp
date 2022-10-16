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

const ll inf = 1LL << 50;

void floydWarshall(vector<vector<ll>> &m) {
   int n = sz(m);
   rep(i, n) m[i][i] = min(m[i][i], 0LL);
   rep(k, n) rep(i, n) rep(j, n) if (m[i][k] != inf && m[k][j] != inf) {
      auto newDist = max(m[i][k] + m[k][j], -inf);
      m[i][j] = min(m[i][j], newDist);
   }
   rep(k, n) if (m[k][k] < 0) rep(i, n) rep(j, n) if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

int32_t main() {
   _upgrade;
   int n, m;
   cin >> n >> m;

   vector<vector<ll>> G(n, vector<ll>(n, inf));

   rep(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      G[--a][--b] = c;
      G[b][a] = c;
   }

   auto dist = G;
   floydWarshall(dist);

   vector<vector<ll>> L(n, vector<ll>(n, -inf));

   int q;
   cin >> q;
   rep(i, q) {
      int a, b, c;
      cin >> a >> b >> c;
      L[--a][--b] = c;
      L[b][a] = c;
   }

   vector<vector<ll>> OK(n, vector<ll>(n, 0));

   rep(v, n) rep(b, n) {
      int maks = -inf;
      rep(u, n) maks = max(maks, L[v][u] - dist[u][b]);
      //  debug(maks);
      rep(a, n) if (a != b && G[a][b] + dist[a][v] <= maks) OK[a][b] = 1;
   }

   //  debug(OK);

   int res = 0;
   rep(i, n) res += accumulate(all(OK[i]), 0);
   assert(res % 2 == 0);
   cout << res / 2 << endl;
}