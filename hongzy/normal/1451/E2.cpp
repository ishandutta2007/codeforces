#include <bits/stdc++.h>
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

const int mod = 1e9 + 7;

const int N = 1 << 17;

int a[N], ans[N];
pii b[N];
int main() {
   int n;
   scanf("%d", &n);
   rep(i, 2, n) {
      printf("XOR %d %d\n", 1, i); fflush(stdout);
      scanf("%d", a + i); b[i] = mp(a[i], i);
   }
   b[1] = mp(0, 1);
   sort(b + 1, b + n + 1);
   bool mark = 0;
   rep(i, 2, n) if(b[i].fs == b[i - 1].fs) {
      mark = 1; int u = b[i].sc, v = b[i - 1].sc;
      printf("OR %d %d\n", u, v); fflush(stdout);
      int x; scanf("%d", &x); ans[u] = ans[v] = x;
      if(u != 1 && v != 1) ans[1] = x ^ a[u];
      rep(j, 2, n) if(j != u && j != v) {
         ans[j] = ans[1] ^ a[j];
      }
      break ;
   }
   if(!mark) {

      rep(i, 2, n) if(a[i] == 1 || a[i] == 2) {
         printf("AND %d %d\n", 1, i); fflush(stdout);
         int x; scanf("%d", &x);
         ans[1] |= x;
      }
      rep(i, 2, n) ans[i] = a[i] ^ ans[1];
   }
   printf("!");
   rep(i, 1, n) {
      printf(" %d", ans[i]);
   }
   puts("");
   fflush(stdout);
   return 0;
}