#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e6 + 5;

int mx = 0;
int a[MAXN];

int main() {
   int n, k; scanf("%d%d", &n, &k);
   rep(i, n) {
      int x; scanf("%d", &x);
      a[i] = x;
      mx = max(a[i], mx);
   }

   for(int i = 2; i <= k; ++i) {
      while(true) {
         if(k % i != 0 || mx < i) break;
         bool ok = false;
         rep(j, n) if(a[j] % i == 0) {
            ok = true; break;
         }
         if(ok) {
            rep(j, n) {
               if(a[j] % i == 0)
                  a[j] /= i;
               mx = max(mx, a[j]);
            }
            k /= i;
         }
         else break;
      }
   }

   if(k == 1) printf("Yes\n");
   else printf("No\n");

   return 0;
}