#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m, p, len;
char s[N][64], ans[64];
int get() {
  int p3;
  char *p1 = new char, *p2 = new char;
  return *p1 ^ *p2 ^ p3;
}
int main() {
  mt19937 e(chrono::system_clock::now().time_since_epoch().count());
  scanf("%d%d%d", &n, &m, &p);
  rep(i, 1, n) scanf("%s", s[i] + 1);
  rep(i, 1, n) rep(j, 1, m) s[i][j] &= 15;
  uniform_int_distribution<int> ran(1, n);
  rep(i, 1, m) ans[i] = '0';
  rep(T, 1, 20) {
    int id = ran(e);
    static int seq[64], sum[1 << 15];
    int z = 0;
    rep(i, 1, m) if(s[id][i]) seq[z ++] = i;
    fill(sum, sum + (1 << z), 0);
    rep(i, 1, n) {
      int f = 0;
      rep(j, 0, z - 1)
        if(s[i][seq[j]])
          f |= 1 << j;
      if(f) sum[f] ++;
    }
    rep(i, 0, z - 1) rep(j, 0, (1 << z) - 1) if(!(j >> i & 1))
      sum[j] += sum[j ^ (1 << i)];
    int mx = 0, res = 0;
    rep(i, 0, (1 << z) - 1)
      if(sum[i] >= (n + 1) / 2) {
        int c = __builtin_popcount(i);
        if(c > mx) mx = c, res = i;
      }
    if(mx > len) {
      len = mx;
      rep(i, 1, m) ans[i] = '0';
      rep(i, 0, z - 1) if(res >> i & 1) ans[seq[i]] = '1';
    }
  }
  // printf("len = %d\n", len);
  puts(ans + 1);
  return 0;
}