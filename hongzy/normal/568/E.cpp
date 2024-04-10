#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], b[N];
int f[N], g[N], len, val[N], pos[N];
bool vis[N];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i);
  scanf("%d", &m);
  rep(i, 1, m) scanf("%d", b + i);
  sort(b + 1, b + m + 1);
  rep(i, 1, n) {
    if(!~a[i]) {
      int p = len + 1;
      per(j, m, 1) {
        while(val[p - 1] >= b[j]) --p;
        val[p] = b[j]; pos[p] = i;
        if(p > len) ++len;
      }
    } else {
      int z = lower_bound(val + 1, val + len + 1, a[i]) - val;
      val[z] = a[i]; pos[z] = i; f[i] = z; g[i] = pos[z - 1];
      if(z > len) ++len;
    }
  }
  // cerr << "len = " << len << endl;
  int id = pos[len], la = INT_MAX;
  int p = m;
  per(i, len, 1) {
    if(~a[id]) {
      la = a[id];
      id = g[id];
    } else {
      while(b[p] >= la) p --;
      vis[p] = 1;
      la = a[id] = b[p];
      p --;
      int w = -1;
      per(j, id - 1, 0)
        if(~a[j] && a[j] < la && f[j] == i - 1) { w = j; break ; }
      if(!~w) {
        per(j, id - 1, 0)
          if(!~a[j]) { w = j; break ; }
      }
      id = w;
    }
  }
  p = 1;
  rep(i, 1, n) {
    if(!~a[i]) {
      while(vis[p]) ++ p;
      a[i] = b[p]; vis[p] = 1;
    }
  }
  rep(i, 1, n) {
    printf("%d%c", a[i], " \n"[i == n]);
  }
  return 0;
}