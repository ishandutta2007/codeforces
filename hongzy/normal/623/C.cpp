#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
int n;
pii a[N], pre[N], suf[N];
ll X[N], Y[N], ans;
ll sqr(ll x) { return x * x; }
ll width(ll *a) {
   return *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1);
}
int Lound(int x, int y, ll up) {
   int l = 1, r = x;
   while(l <= r) {
      int mid = (l + r) >> 1;
      if(abs(a[mid].fs) <= y && sqr(a[mid].fs - a[x].fs) <= up) r = mid - 1;
      else l = mid + 1;
   }
   return r + 1;
}
int Round(int x, int y, ll up) {
   int l = x, r = n;
   while(l <= r) {
      int mid = (l + r) >> 1;
      if(abs(a[mid].fs) <= y && sqr(a[mid].fs - a[x].fs) <= up) l = mid + 1;
      else r = mid - 1;
   }
   return l - 1;
}
ll ABS(ll x) {
   if(abs(x) <= (ll) 1e8) return abs(x);
   return 0;
}
ll ABS(pii x) { return max(ABS(x.fs), ABS(x.sc)); }
bool check(ll mid) {
   rep(i, 1, n) { //x Left < Right
      if(a[i].fs >= 0) {
         int l = Lound(i, a[i].fs, mid);
         int m = max(ABS(pre[l - 1]), ABS(suf[i + 1]));
         int mx = max(pre[l - 1].fs, suf[i + 1].fs);
         int mn = min(pre[l - 1].sc, suf[i + 1].sc);
         if(sqr(m) + sqr(a[i].fs) <= mid && sqr(max(0, mx - mn)) <= mid) {
            return 1;
         }
      } else { //x Left > Right
         int r = Round(i, - a[i].fs, mid);
         int m = max(ABS(pre[i - 1]), ABS(suf[r + 1]));
         int mx = max(pre[i - 1].fs, suf[r + 1].fs);
         int mn = min(pre[i - 1].sc, suf[r + 1].sc);
         if(sqr(m) + sqr(a[i].fs) <= mid && sqr(max(0, mx - mn)) <= mid) {
            return 1;
         }
      }
   }
   return 0;
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d%d", &a[i].fs, &a[i].sc), X[i] = a[i].fs, Y[i] = a[i].sc;
   ans = sqr(min(width(Y), width(X)));
   sort(a + 1, a + n + 1);
   pre[0] = suf[n + 1] = mp(-2e8, 2e8);
   rep(i, 1, n) pre[i] = mp(max(pre[i - 1].fs, a[i].sc), min(pre[i - 1].sc, a[i].sc));
   per(i, n, 1) suf[i] = mp(max(suf[i + 1].fs, a[i].sc), min(suf[i + 1].sc, a[i].sc));
   ll l = 0, r = 1e18, res = -1;
   while(l <= r) {
      ll mid = (l + r) >> 1;
      if(check(mid)) r = (res = mid) - 1;
      else l = mid + 1;
   }
   if(~ res) ans = min(ans, res);
   printf("%lld\n", ans);
   return 0;
}