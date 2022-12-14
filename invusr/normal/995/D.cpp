#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

inline int getint() {
  static char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');

  if (c == '-') {
    int res = 0;
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return -res;
  } else {
    int res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return res;
  }
}

int n, r;
int a[1 << 18];

r32 sum = 0;

int main() {
  cin >> n >> r;
  for (int i = 0; i < 1 << n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  printf("%.8f\n", sum / (r32)(1 << n));
  while (r--) {
    int z, g;
    scanf("%d%d", &z, &g);

    sum -= a[z];
    sum += (a[z] = g);
    printf("%.8f\n", sum / (r32)(1 << n));
  }

  return 0;
}