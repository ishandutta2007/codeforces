#include <bits/stdc++.h>
using namespace std;

const int P = 1e6 + 3;
int n = 11;
int a[15][15], ans[15];

inline int qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

void gauss() {
  for (int i = 0, now = 0; i < n; i++) {
    int p = now;
    while (p < n && !a[p][i]) p++;
    if (p == n) continue;
    if (p != now) {
      for (int j = 0; j <= n; j++) {
        swap(a[p][j], a[now][j]);
      }
    }
    for (int j = now + 1; j < n; j++) {
      int t = 1ll * a[j][i] * qp(a[now][i], P - 2) % P;
      for (int k = i; k <= n; k++) {
        a[j][k] = (a[j][k] - 1ll * t * a[now][k] % P + P) % P;
      }
    }
    now++;
  }
  for (int i = n - 1; ~i; i--) {
    for (int j = i + 1; j < n; j++) {
      a[i][n] = (a[i][n] - 1ll * a[i][j] * ans[j] % P + P) % P;
    }
    ans[i] = 1ll * a[i][n] * qp(a[i][i], P - 2) % P;
  }
}

int main() {
  for (int i = 0; i < n; i++) {
    cout << "? " << i << endl, cout.flush();
    cin >> a[i][n], a[i][n] %= P;
    for (int j = 0, v = 1; j < n; j++) {
      a[i][j] = v, v = v * i % P;
    }
  }
  gauss();
  int res = -1;
  for (int i = 0; i < P; i++) {
    int v = 0;
    for (int j = n - 1; ~j; j--) {
      v = (1ll * v * i + ans[j]) % P;
    }
    if (!v) {
      res = i; break;
    }
  }
  printf("! %d", res);
  return 0;
}