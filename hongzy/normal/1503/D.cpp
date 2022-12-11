#include <bits/stdc++.h>
#define pb push_back
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
int n, ans, f[N], c[N], suf[N];
void calc(int l, int r) {
  static int v1[N], v2[N];
  int n1 = 0, n2 = 0, c1 = 0, c2 = 0;
  v1[0] = v2[0] = 1 << 29;
  rep(i, l, r) {
    bool o1 = v1[n1] > f[i];
    bool o2 = v2[n2] > f[i];
    if(!o1 && !o2) { puts("-1"); exit(0); }
    if(!o2 || (v1[n1] < v2[n2])) v1[++ n1] = f[i], c1 += c[i];
    else v2[++ n2] = f[i], c2 += c[i];
  }
  ans += min(c1 + n2 - c2, n1 - c1 + c2);
}
int main() {
  scanf("%d", &n);
  int x, y;
  rep(i, 1, n) {
    scanf("%d%d", &x, &y);
    if(x <= n && y <= n) { puts("-1"); return 0; }
    bool bo = 0;
    if(x > y) { swap(x, y); bo = 1; }
    f[x] = y; c[x] = bo;
  }
  suf[n] = f[n];
  per(i, n - 1, 1) suf[i] = max(suf[i + 1], f[i]);
  int Min = 1 << 29, st = 1;
  rep(i, 2, n) {
    Min = min(Min, f[i - 1]);
    if(Min > suf[i]) {
      calc(st, i - 1); st = i;
    }
  }
  calc(st, n);
  printf("%d\n", ans);
  return 0;
}