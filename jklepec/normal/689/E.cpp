#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 4e5 + 5, mod = 1e9 + 7;

int fact[MAXN], rfact[MAXN];

int add(int x, int y) {
   x += y;
   if(x >= mod) return x - mod;
   return x;
}
int mul(int x, int y) {
   return (ll) x * y % mod;
}
int sub(int x, int y) {
   x -= y;
   if(x < 0) return x + mod;
   return x;
}
int exp(int x, int y) {
   int ret = x;
   y -= 1;
   while(y) {
      if(y & 1)
         ret = mul(ret, x);
      x = mul(x, x);
      y /= 2;
   }
   return ret;
}
int povrh(int n, int k) {
   if(n < k) return 0;
   if(n == k) return 1;
   return mul(mul(fact[n], rfact[k]), rfact[n - k]);
}

int n, k;

vector<point> ev;

void load() {
   fact[0] = 1;
   rfact[0] = 1;
   for(int i = 1; i < MAXN / 2; ++i) {
      fact[i] = mul(fact[i - 1], i);
      rfact[i] = exp(fact[i], mod - 2);
   }
   scanf("%d%d", &n, &k);
   rep(i, n) {
      int x, y; scanf("%d%d", &x, &y);
      ev.push_back({x, 0});
      ev.push_back({y, 1});
   }
   sort(ev.begin(), ev.end());
}

int sol;

void solve() {
   int l = ev[0].first - 1, dp = 0;
   for(int i = 0; i < 2 * n;) {
      int curr = ev[i].first, open = 0, close = 0;
      for(; i < 2 * n && ev[i].first == curr; ++i) {
         if(ev[i].second)
            close ++;
         else
            open ++;
      }
      sol = add(sol, mul(povrh(dp, k), curr - l - 1));
      dp += open;
      sol = add(sol, povrh(dp, k));
      dp -= close;
      l = curr;
   }
   printf("%d", sol);
}

int main() {
   load();
   solve();
}