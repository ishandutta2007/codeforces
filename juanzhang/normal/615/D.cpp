#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, P = 1e9 + 7;
int N, n, tot, p[maxn], cnt[maxn];

int get_phi(int x) {
  int res = x, tmp = sqrt(x);
  for (int i = 2; i <= tmp; i++) {
    if (x % i == 0) {
      res = res / x * (x - 1);
      while (x % i == 0) x /= i;
    }
  }
  return x > 1 ? res / x * (x - 1) : res;
}

void sieve() {
  int tmp = sqrt(N);
  for (int i = 2; i <= tmp; i++) {
    if (p[i]) continue;
    for (int j = i * i; j <= N; j += i) {
      p[j] = 1;
    }
  }
  for (int i = 2; i <= N; i++) {
    if (!p[i]) p[++tot] = i;
  }
}

void add(int x) {
  int tmp = sqrt(x);
  for (int i = 1; i <= tot && p[i] <= tmp; i++) {
    while (x % p[i] == 0) {
      cnt[i]++, x /= p[i];
    }
  }
  if (x > 1) {
    cnt[lower_bound(p + 1, p + tot + 1, x) - p]++;
  }
}

inline int qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

int main() {
  N = 200000;
  sieve();
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x), add(x);
  }
  int mod = get_phi(P);
  int ans = 1, s = 1;
  for (int i = 1; i <= tot; i++) {
    int val = qp(p[i], 1ll * cnt[i] * (cnt[i] + 1) / 2 % mod);
    ans = 1ll * qp(ans, cnt[i] + 1) * qp(val, s) % P;
    s = 1ll * s * (cnt[i] + 1) % mod;
  }
  printf("%d", ans);
  return 0;
}