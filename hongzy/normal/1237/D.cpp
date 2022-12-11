#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
// mt19937_64 
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 3e5 + 10;
const int INF = 1e9;
int n, a[N], ans[N];
int st[N], top;
void ins(int id) {
   while(top && a[st[top]] >= a[id]) {
      top --;
   }
   st[++ top] = id;
}
int qry(int v) { //latest <= v
   int l = 1, r = top, ans = INF;
   while(l <= r) {
      int mid = (l + r) >> 1;
      if(2 * a[st[mid]] <= v) l = (ans = mid) + 1;
      else r = mid - 1;
   }
   if(ans < INF) ans = st[ans];
   return ans;
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d", a + i);
   rep(i, n + 1, 3 * n) a[i] = a[i - n];
   ans[3 * n] = INF; ins(3 * n);
   per(i, 3 * n - 1, 1) {
      ans[i] = min(ans[i + 1], qry(a[i] - 1));
      ins(i);
   }
   rep(i, 1, n) printf("%d%c", ans[i] == INF ? -1 : ans[i] - i, " \n"[i == n]);
   return 0;
}