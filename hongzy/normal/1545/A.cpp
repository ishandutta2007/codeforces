#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
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
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int n, a[N], c[N][2], b[N];
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i), b[i] = a[i];
    int m = *max_element(a + 1, a + n + 1);
    rep(i, 1, m) c[i][0] = c[i][1] = 0;
    rep(i, 1, n) c[a[i]][i & 1] ++;
    sort(b + 1, b + n + 1);
    rep(i, 1, n) c[b[i]][i & 1] --;
    bool fail = 0;
    rep(i, 1, m) if(c[i][0] || c[i][1]) fail = 1;
    puts(fail ? "NO" : "YES");
  }  
  return 0;
}