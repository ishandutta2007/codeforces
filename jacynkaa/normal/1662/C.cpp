#define debug if (0)
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define SIZE(c) ((int)((c).size()))
#define ALL(v) (v).begin(), (v).end()
#define VAR(v) #v << " " << v << " "
#define pb push_back
#define mp make_pair
#define st first
#define nd second
template <typename T> ostream &dbg_print(ostream &out, const T &dbg_t) {
   out << "[";
   for (auto i : dbg_t)
      out << i << ", ";
   out << "]";
   return out;
}
template <typename T> ostream &operator<<(ostream &out, const set<T> &dbg_t) { return dbg_print(out, dbg_t); }
template <typename T> ostream &operator<<(ostream &out, const vector<T> &dbg_t) { return dbg_print(out, dbg_t); }
template <typename S, typename T> ostream &operator<<(ostream &out, const pair<S, T> &rhs) {
   out << "(" << rhs.st << "," << rhs.nd << ")";
   return out;
}
template <typename T> void max_e(T &aaa, const T &bbb) { aaa = max(aaa, bbb); }
template <typename T> void min_e(T &aaa, const T &bbb) { aaa = min(aaa, bbb); }
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int MOD = 998244353;

VI mul(vector<VI> a, VI b) {
   int n = SIZE(b);
   REP(i, n) REP(j, n) assert(a[i][j] >= 0 && a[i][j] < MOD);
   REP(i, n) assert(b[i] >= 0 && b[i] < MOD);
   VI r(n, 0);
   REP(i, n) REP(j, n) r[i] = int((r[i] + LL(a[i][j]) * b[j]) % MOD);
   return r;
}

vector<VI> mul(vector<VI> a, vector<VI> b) {
   int n = SIZE(a);
   vector<VI> r(n, VI(n, 0));
   REP(i, n) REP(j, n) REP(k, n) r[i][j] = int((r[i][j] + LL(a[i][k]) * b[k][j]) % MOD);
   return r;
}

vector<VI> pow(vector<VI> a, int k) {
   int n = SIZE(a);
   if (k == 0) {
      vector<VI> r(n, VI(n, 0));
      REP(i, n) r[i][i] = 1;
      return r;
   } else if (k % 2 == 1)
      return mul(pow(a, k - 1), a);
   vector<VI> tmp = pow(a, k / 2);
   return mul(tmp, tmp);
}

ostream &operator<<(ostream &out, vector<VI> m) {
   out << endl;
   for (auto i : m)
      out << i << endl;
   return out;
}

void moddec(int &a) {
   a--;
   if (a < 0)
      a += MOD;
}

int n;
vector<PII> edges;

VI solve(int d) {
   vector<VI> m(3 * n, VI(3 * n, 0));
   for (auto i : edges) {
      m[n + i.st][i.nd] = 1;
      m[n + i.st][n + i.nd] = 1;
      m[2 * n + i.nd][i.nd]++;
      m[2 * n + i.nd][n + i.nd]++;
   }
   REP(i, n) moddec(m[2 * n + i][n + i]);
   REP(i, n) moddec(m[n + i][2 * n + i]);
   // v[s] = 1;

   m = pow(m, d);
   vector<int> res(n);
   REP(i, n) {
      VI v(3 * n, 0);
      v[i] = 1;
      v = mul(m, v);
      // debug cout << VAR(m) << endl;
      // debug {
      //    REP(j, n) cout << "(" << v[j] << "," << v[j + n] << "," << v[j + 2 * n] << ") ";
      //    cout << endl;
      // }
      REP(i, n) v[i] = (v[i] + v[n + i]) % MOD;
      res[i] = v[i];
   }

   return res;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int z;
   z = 1;
   while (z--) {
      int m, d;
      cin >> n >> m >> d;
      edges.clear();
      while (m--) {
         int a, b;
         cin >> a >> b;
         a--;
         b--;
         edges.pb(mp(a, b));
         edges.pb(mp(b, a));
      }
      VI result = solve(d);
      auto res = accumulate(ALL(result), 0ll);
      cout << res % MOD << endl;
      // REP(i, SIZE(result)) {
      //    cout << result[i];
      //    if (i + 1 < SIZE(result))
      //       cout << " ";
      // }
      // cout << endl;
   }
   return 0;
}