#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 310;
int x, k;
double p, q, f[N][N];
int main(){
  scanf("%d%d%lf", &x, &k, &p);
  p /= 100; q = 1.0 - p;
  rep(i, 0, k) f[0][i] = (double)__builtin_ctz(x + i);
  rep(i, 1, k) rep(j, 0, k) {
    f[i][j] += f[i - 1][j + 1] * q;
    if(j * 2 <= k) f[i][j << 1] += (f[i - 1][j] + 1.0) * p;
  }
  printf("%.15lf\n", f[k][0]);
  return 0;
}