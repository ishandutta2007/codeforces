#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1024;
int t, n, m, a[N][N], ans[N][N];
char s[1 << 20];
int calc(int x) {
   return ((x - 1) % n + n) % n + 1;
}
int main() {
   scanf("%d", &t);
   while(t --) {
      scanf("%d%d", &n, &m);
      rep(i, 1, n) rep(j, 1, n) scanf("%d", a[i] + j);
      scanf("%s", s + 1);
      int x = 0, y = 0, z = 0, dx = 0, dy = 1, dz = 2;
      rep(i, 1, m) {
         if(s[i] == 'L') y --;
         if(s[i] == 'R') y ++;
         if(s[i] == 'U') x --;
         if(s[i] == 'D') x ++;
         if(s[i] == 'I') swap(y, z), swap(dy, dz);
         if(s[i] == 'C') swap(x, z), swap(dx, dz);
      }
      rep(i, 1, n) rep(j, 1, n) {
         int arr[3] = {i, j, a[i][j]};
         ans[calc(arr[dx] + x)][calc(arr[dy] + y)] = calc(arr[dz] + z);
      }
      rep(i, 1, n) rep(j, 1, n) printf("%d%c", ans[i][j], " \n"[j == n]);
   }
   return 0;
}