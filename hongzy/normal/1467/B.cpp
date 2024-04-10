#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

const int N = 3e5 + 10;

int n, a[N], c[N];
bool pd(int i) {
   return i == n || i == 1 ? 0 : (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]);
}
int chk(int i, int v) {
   int ans = 0, tmp = a[i]; a[i] = v;
   rep(d, -1, 1) {
      int t = pd(i + d);
      if(!t && c[i + d]) ans ++;
      if(t && !c[i + d]) ans --;
   }
   a[i] = tmp;
   return ans;
}
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d", &n);
      rep(i, 1, n) scanf("%d", a + i);
      int ans = 0, res = 0;
      c[1] = c[n] = 0;
      rep(i, 2, n - 1) ans += (c[i] = pd(i));
      if(n >= 2 && (c[2] || c[n - 1])) res = 1;
      rep(i, 2, n - 1) {
         res = max(res, max(chk(i, a[i - 1]), chk(i, a[i + 1])));
      }
      ans -= res;
      printf("%d\n", ans);
   }
   return 0;
}