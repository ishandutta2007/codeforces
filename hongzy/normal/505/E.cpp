#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

typedef long long ll;

const int N = 4e5 + 10;

int n, m, k, p;
ll h[N], a[N];
struct node {
   ll t, a, h, hi;
   bool operator < (const node &b) const {
      return t > b.t;
   }
};
priority_queue<node> pq;
bool check(ll H) {
   while(pq.size()) pq.pop();
   rep(i, 1, n) {
      pq.push({H / a[i], a[i], H, h[i]});
   }
   ll c = 0;
   rep(i, 1, m) {
      if(pq.top().t - i < 0) return 0;
      rep(j, 1, k) {
         if(pq.top().t >= m) {
            break ;
         }
         node x = pq.top(); pq.pop();
         x.h += p; x.t = x.h / x.a; pq.push(x); c ++;
      }
   }
   rep(i, 1, n) {
      node x = pq.top(); pq.pop();
      c += max(0ll, (x.hi - (x.h - m * x.a) + p - 1) / p);
      if(c > m * k) return 0;
   }
   return 1;
}
int main() {
   scanf("%d%d%d%d", &n, &m, &k, &p);
   ll l = 0, r = 0, ans = -1;
   rep(i, 1, n) scanf("%lld%lld", h + i, a + i), r = max(r, h[i] + a[i] * m);
   while(l <= r) {
      ll mid = (l + r) >> 1;
      if(check(mid)) r = (ans = mid) - 1;
      else l = mid + 1;
   }
   printf("%lld\n", ans);
   return 0;
}