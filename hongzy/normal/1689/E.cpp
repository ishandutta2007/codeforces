#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2048;
int n, a[N], ans;
int lowbit(int x) { return x & (-x); }

int f[N];
int find(int u) {
  return u == f[u] ? u : f[u] = find(f[u]);
}
void unite(int u, int v) {
  f[find(u)] = find(v);
}
bool check() {
  rep(i, 1, 30 + n) f[i] = i;
  rep(i, 1, n) {
    int x = a[i];
    while(x) {
      int v = __builtin_ctz(x) + 1;
      unite(v, 30 + i);
      x &= x - 1;
    }
  }
  rep(i, 1, n) if(find(30 + i) != find(30 + 1)) return 0;
  printf("%d\n", ans);
  rep(i, 1, n) printf("%d%c", a[i], " \n"[i == n]);
  return 1;
}
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n); ans = 0;
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) if(!a[i]) ++ ans, a[i] = 1;
    if(check()) continue ;
    ++ans;
    bool tag = 0;
    rep(i, 1, n) {
      a[i] ++;
      if(check()) { tag = 1; break ; }
      a[i] --;
      if(a[i]) {
        a[i] --;
        if(check()) { tag = 1; break ; }
        a[i] ++;
      }
    }
    if(tag) continue ;
    ++ans;
    int mx = 0, cnt = 0;
    rep(i, 1, n) mx = max(mx, lowbit(a[i]));
    rep(i, 1, n) {
      if(mx == lowbit(a[i])) {
        ++cnt;
        if(cnt == 1) {
          a[i] --;
        }
        if(cnt == 2) {
          a[i] ++;
          break;
        }
      }
    }
    printf("%d\n", ans);
    rep(i, 1, n) printf("%d%c", a[i], " \n"[i == n]);
  }
  return 0;
}