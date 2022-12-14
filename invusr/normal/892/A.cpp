#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

inline int getint() {
  static char c;
  while ((c = getchar()) < '0' || c > '9');

  int res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') {
    res = res * 10 + c - '0';
  }
  return res;
}

const int MaxN = 100000;

int n;
int a[MaxN], b[MaxN];

s64 sum = 0;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    a[i] = getint();
    sum += a[i];
  }
  for (int i = 0; i < n; ++i) {
    b[i] = getint();
  }

  sort(b, b + n);

  if (n == 1 || sum <= b[n - 1] + b[n - 2]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}