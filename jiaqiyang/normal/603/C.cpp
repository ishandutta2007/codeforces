#include <cstdio>

const int N = 100000 + 10;

int n, k, a[N];

inline int mex(int a, int b) {
  for (int i = 0;; ++i) if (i != a && i != b) return i;
}

const int b[] = {0, 1, 0, 1, 2, 0, 2, 0, 1, 0};

int sg(int x) {
  if (!x) return 0;
  if (k & 1) {
    if (x < 10) return b[x];
    if (x & 1) return 0;
    return mex(0, sg(x / 2));
   } else {
    if (x < 3) return x;
    return !(x & 1);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans ^= sg(a[i]);
  puts(ans ? "Kevin" : "Nicky");
  return 0;
}