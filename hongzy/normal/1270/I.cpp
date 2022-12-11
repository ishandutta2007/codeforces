#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 512;
int k, n, t, x[N], y[N];
ll a[N][N], c[N][N], d[N][N];
vector<int> vx, vy;
int main() {
   scanf("%d", &k); n = 1 << k;
   for(int i = 0; i < n; i ++)
      for(int j = 0; j < n; j ++)
         scanf("%lld", a[i] + j);
   scanf("%d", &t);
   for(int i = 0; i < t; i ++)
      scanf("%d%d", x + i, y + i);
   for(int i = 0; i < k; i ++) {
      vector<int>().swap(vx); vector<int>().swap(vy);
      if(!i) {
         for(int j = 0; j < t; j ++) vx.pb(x[j]), vy.pb(y[j]);
      } else {
         for(int x = 0; x < n; x ++) for(int y = 0; y < n; y ++) d[x][y] = 0;
         for(int j = 0; j < t; j ++) x[j] = (x[j] << 1) & (n - 1), y[j] = (y[j] << 1) & (n - 1), d[x[j]][y[j]] ^= 1;
         for(int x = 0; x < n; x ++) for(int y = 0; y < n; y ++) if(d[x][y]) vx.pb(x), vy.pb(y);
      }
      for(int x = 0; x < n; x ++) for(int y = 0; y < n; y ++) {
         d[x][y] = 0;
         for(int j = 0; j < (int)vx.size(); j ++) {
            d[x][y] ^= a[(x - vx[j]) & (n - 1)][(y - vy[j]) & (n - 1)];
         }
      }
      for(int x = 0; x < n; x ++) for(int y = 0; y < n; y ++) a[x][y] = d[x][y];
   }
   int ans = 0;
   for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) ans += a[i][j] > 0;
   printf("%d\n", ans);
   return 0;
}