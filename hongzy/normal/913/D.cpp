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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
struct node {
  int t, a, id;
} a[N];
pii b[N];
int n, T, sz = 0, ans = 0;

priority_queue<int> h;
int main() {
  scanf("%d%d", &n, &T);
  rep(i, 1, n) {
    scanf("%d%d", &a[i].a, &a[i].t);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, [&](node x, node y) {
    return x.a > y.a;
  });
  int p = 0, s = 0;
  per(i, n, 1) {
    while(p < n && a[p + 1].a >= i) {
      p ++;
      h.push(a[p].t);
      s += a[p].t;
    }
    while(h.size() > i) {
      s -= h.top(); h.pop();
    }
    if(h.size() == i && s <= T) {
      rep(j, 1, p) b[j] = pii(a[j].t, a[j].id);
      sort(b + 1, b + p + 1);
      printf("%d\n%d\n", i, i);
      rep(j, 1, i) printf("%d ", b[j].sc);
      puts("");
      return 0;
    }
  }
  puts("0\n0");
  return 0;
}