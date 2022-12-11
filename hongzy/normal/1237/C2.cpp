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

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
struct node {
   int x, y, z, id;
   bool same2D(node b) {
      return x == b.x && y == b.y;
   }
   bool same1D(node b) {
      return x == b.x;
   }
   bool operator < (const node b) const {
      if(x ^ b.x) return x < b.x;
      if(y ^ b.y) return y < b.y;
      if(z ^ b.z) return z < b.z;
      return id < b.id;
   }
} a[N], st[N];
int n, top;
int main() {
   scanf("%d", &n);
   rep(i, 1, n) {
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
      a[i].id = i;
   }
   sort(a + 1, a + n + 1);
   rep(i, 1, n) {
      if(!top) st[++ top] = a[i];
      else {
         if(a[i].same2D(st[top])) {
            printf("%d %d\n", a[i].id, st[top].id);
            top --;
         } else {
            st[++ top] = a[i];
         }
      }
   }
   swap(top, n); swap(st, a);
   top = 0;
   rep(i, 1, n) {
      if(!top) st[++ top] = a[i];
      else {
         if(a[i].same1D(st[top])) {
            printf("%d %d\n", a[i].id, st[top].id);
            top --;
         } else {
            st[++ top] = a[i];
         }
      }
   }
   for(int i = 1; i <= top - 1; i += 2) {
      printf("%d %d\n", st[i].id, st[i + 1].id);
   }
   return 0;
}