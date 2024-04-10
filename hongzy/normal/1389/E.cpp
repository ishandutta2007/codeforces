#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int gcd(int a, int b) {
   return !b ? a : gcd(b, a % b);
}
ll S(ll n) {
   return n <= 0 ? 0 : n * (n + 1ll) / 2;
}
int main() {
   int T; scanf("%d",&T);
   while(T --) {
      int n, m, w;
      scanf("%d%d%d", &n, &m, &w);
      if(m != 1) {
         ll g = gcd(m - 1, w); w /= g;
         ll cnt = min(n, m) / w, sum = w * S(min(n, m) / w);
         printf("%lld\n", cnt * min(n, m) - sum);
      } else {
         ll res = S(min(n, m) - 1);
         printf("%lld\n", res);
      }
   }
   return 0;
}