#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
int t, n, k;
int main() {
   scanf("%d", &t);
   while(t --) {
      scanf("%d%d", &n, &k);
      rep(i, 1, 2 * k - n - 1) printf("%d ", i);
      rep(i, 1, n - k + 1) printf("%d ", k - i + 1);
      puts("");
   }
   return 0;
}