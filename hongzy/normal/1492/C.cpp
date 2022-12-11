#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 5e5 + 10;
const int mod = 1e9 + 7;
int n, m, pre[N], suf[N];
char s[N], t[N];
bool check(int mid) {
  rep(i, 1, n - mid) {
    if(pre[i] && suf[i + mid] <= n && pre[i] >= suf[i + mid] - 1) {
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s", s + 1, t + 1);
  rep(i, 1, n) {
    pre[i] = pre[i - 1];
    if(pre[i] <= m && t[pre[i] + 1] == s[i]) {
      pre[i] ++;
    }
  }
  suf[n + 1] = m + 1;
  per(i, n, 1) {
    suf[i] = suf[i + 1];
    if(suf[i] >= 1 && t[suf[i] - 1] == s[i]) {
      suf[i] --;
    }
  }
  int l = 0, r = n;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(check(mid)) l = mid + 1;
    else r = mid - 1;
  }
  printf("%d\n", l - 1);
  return 0;
}