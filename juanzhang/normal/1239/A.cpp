#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10, P = 1e9 + 7;
int n, m, f[maxn];

int main() {
  scanf("%d %d", &n, &m);
  f[0] = f[1] = 1;
  for (int i = 2; i <= max(n, m); i++) {
    f[i] = (f[i - 1] + f[i - 2]) % P;
  }
  printf("%d\n", ((f[n] * 2ll + f[m] * 2ll - 2 + P) % P));
  return 0;
}