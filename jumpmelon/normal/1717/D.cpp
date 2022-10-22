#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 100000, P = 1000000007;
int Fac[MAXN + 1], InvFac[MAXN + 1];

int inv(int x) {
  return x == 1 ? 1 : int(big(P - P / x) * inv(P % x) % P);
}

inline int C(int k, int r) {
  return int((big)Fac[k] * InvFac[r] % P * InvFac[k - r] % P);
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  Fac[0] = 1;
  for (int i = 1; i <= n; i++)
    Fac[i] = int((big)Fac[i - 1] * i % P);
  InvFac[n] = inv(Fac[n]);
  for (int i = n; i >= 1; i--)
    InvFac[i - 1] = int((big)InvFac[i] * i % P);
  
  int ans = 0;
  for (int r = 0; r <= k && r <= n; r++)
    ans = (ans + C(n, r)) % P;
  printf("%d\n", ans);

  return 0;
}