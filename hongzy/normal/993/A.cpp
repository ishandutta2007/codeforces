#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;
 
const int N = 4e5 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
struct point {
   db x, y;
   void in() { scanf("%lf%lf", &x, &y); }
   point operator - (point b) { return {x - b.x, y - b.y}; }
   point operator + (point b) { return {x + b.x, y + b.y}; }
   point operator * (db z) { return {x * z, y * z}; }
   db det(point b) {
      return x * b.y - y * b.x;
   }
} a[4], b[4];
bool inc(point a, point *b) {
   static bool tag[2]; tag[0] = tag[1] = 0;
   for(int i = 0; i < 4; i ++) {
      int j = i == 3 ? 0 : i + 1;
      db y = (b[j] - b[i]).det(a - b[i]);
      if(fabs(y) > 1e-15) tag[y > 0] = 1;
   }
   return !(tag[1] && tag[0]);
}
int main() {
   for(int i = 0; i < 4; i ++) a[i].in();
   for(int i = 0; i < 4; i ++) b[i].in();
   bool t = 0;
   for(int i = 0; i < 4; i ++) t |= inc(a[i], b) || inc(b[i], a);
   t |= inc((a[0] + a[2]) * 0.5, b);
   t |= inc((b[0] + b[2]) * 0.5, a);
   puts(t ? "YES" : "NO");
   return 0;
}