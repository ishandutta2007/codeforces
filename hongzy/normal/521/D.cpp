#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

typedef long double db;
typedef long long ll;
const int N = 2e5 + 10;
int n, m, k, a[N], t[N], p[N], y[N];
pii as[N];
vector<pii> add[N];
vector< pair<db, int> > op;
int main() {
   scanf("%d%d%d", &n, &m, &k);
   rep(i, 1, n) scanf("%d", a + i);
   rep(i, 1, m) {
      scanf("%d%d%d", t + i, p + i, y + i);
      if(t[i] == 1) {
         as[p[i]] = max(as[p[i]], mp(y[i], i));
      } else if(t[i] == 2) {
         add[p[i]].emplace_back(y[i], i);
      } else {
         op.emplace_back(y[i], i);
      }
   }
   rep(i, 1, n) if(a[i] < as[i].fs) add[i].emplace_back(mp(as[i].fs - a[i], as[i].sc));
   rep(i, 1, n) {
      sort(add[i].begin(), add[i].end(), greater<pii>());
      ll y = a[i];
      for(auto z : add[i]) {
         op.pb(mp((y + z.fs) / (db) y, z.sc));
         y += z.fs;
      }
   }
   int x = min((int) op.size(), k);
   sort(op.begin(), op.end(), greater< pair<db, int> >());
   sort(op.begin(), op.begin() + x, [](const auto &x, const auto &y) { return t[x.sc] < t[y.sc]; });
   printf("%d\n", x);
   rep(i, 0, x - 1) printf("%d ", op[i].sc);
   return 0;
}