#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

const int N = 2e5 + 10;

int n, ans, sqrtN, m, x, a[N], c[N];
void solve(int y) {
   static int buf[N + N];
   rep(i, -n, n) buf[n + i] = -1;
   buf[n + 0] = 0;
   int s = 0;
   rep(i, 1, n) {
      s += (a[i] == x) - (a[i] == y);
      if(~ buf[n + s]) ans = max(ans, i - buf[n + s]);
      else buf[n + s] = i;
   }
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d", a + i), c[a[i]] ++;
   int m = *max_element(c + 1, c + n + 1);
   if(count(c + 1, c + n + 1, m) > 1) { printf("%d\n", n); return 0; }
   rep(i, 1, n) if(c[i] == m) x = i;
   sqrtN = (int)ceil(sqrt(n));
   rep(i, 1, n) if(i != x && c[i] >= sqrtN) solve(i);
   static int buf[N];
   rep(t, 1, sqrtN) {
      fill(c + 1, c + n + 1, 0);
      fill(buf + 1, buf + n + 1, 0);
      buf[0] = n;
      int mx = 0, j = 1;
      rep(i, 1, n) {
         buf[ c[a[i]] ] --;
         buf[ ++ c[a[i]] ] ++;
         while(buf[mx + 1]) mx ++;
         while(!buf[mx]) mx --;
         while(mx > t) {
            buf[ c[a[j]] ] --;
            buf[ -- c[a[j]] ] ++;
            j ++;
            while(buf[mx + 1]) mx ++;
            while(!buf[mx]) mx --;
         }
         if(buf[mx] > 1) ans = max(ans, i - j + 1);
      }
   }
   printf("%d\n", ans);
   return 0;
}