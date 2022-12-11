#include <cstdio>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef double db;
const int N = 110;
int n;
db p[N], f[N], ans;
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%lf", p + i), p[i] /= 100;
   rep(i, 1, n) f[i] = p[i];
   db gla = 1;
   rep(i, 1, n) gla *= f[i];
   ans = n * gla;
   rep(i, n + 1, 300000) {
      db t = 0, g; int k = 1;
      rep(j, 1, n) {
         db c = (1 - f[j]) * p[j] / f[j];
         if(c > t) t = c, k = j;
      }
      // if(i <= 15) printf("%d %Lf!!\n", k, t);
      db F = f[k] + (1 - f[k]) * p[k];
      g = gla * F / f[k];
      ans += i * (g - gla);
      gla = g; f[k] = F;
   }
   printf("%.10lf\n", (double) ans);
   return 0;
}