#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 110;
const int mod = 1e9 + 7;
int n, m, c[N], f[N], vis[N], cnt[N];
bool is_end[N];
bool pd() {
  int s = 0;
  per(i, m-1, 1)
    if(cnt[i])
        s = i, i = 0;
  rep(i, 1, s)
    if(cnt[i] != 1)
      return 0;
  return *cnt == 2;
}
int main() {
  *f = *(f+1) = 1;
  n = 100;
  rep(i, 2, n) {
    f[i] = f[i-1] + f[i-2];
    if(f[i] > int(1e9))
      break;
    m = i;
  }
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", c + i);
    if(n == 1) {
      puts(c[1] == 1 ? "YES" : "NO");
      continue ;
    }
    fill(cnt, cnt + m, 0);
    fill(is_end, is_end + m, 0);
    per(i, n, 1) {
      int x = c[i];
      per(j, m, 1) if(f[j] <= x) {
        ++cnt[j-1];
        x -= f[j];
        if(!x)
          is_end[j-1] = 1;
      }
    }
    bool flag = 0;
    if(pd()) {
      flag = 1;
    } else {
      int s = 0;
      per(i, m-1, 1)
        if(cnt[i])
          s = i, i = 0;
      bool ok = *cnt < 2;
      for(int z = 2; z <= s; z += 2) {
        ok &= cnt[z-1] == 0;
        if(!ok) break ;
        // printf("z = %d!\n", z);
        if(cnt[z] && is_end[z]) {
          cnt[z] --;
          for(int z0 = z-1; z0 >= 1; z0 -= 2)
            ++cnt[z0];
          cnt[0]++;

          if(pd()) {
            flag = 1;
            break;
          }

          cnt[z] ++;
          for(int z0 = z-1; z0 >= 1; z0 -= 2)
            --cnt[z0];
          cnt[0]--;
        }
      }
    }
    puts(flag ? "YES" : "NO");
  }
  return 0;
}