#include <bits/stdc++.h>
using namespace std;

inline int getint() {
  static char c;
  while ((c = getchar()) < '0' || c > '9');

  int res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') {
    res = res * 10 + c - '0';
  }
  return res;
}

const int MaxN = 10000;

int n;
int a[MaxN + 1], b[MaxN + 1];
int c[MaxN + 1];

inline bool comparator(const int &i, const int &j) {
  return a[i] < a[j];
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      a[i] = getint();
      b[i] = i;
    }

    sort(b, b + n, comparator);

    for (int i = 0; i < n; ++i) {
      c[b[i]] = a[b[(i + 1) % n]];
    }
    for (int i = 0; i < n; ++i) {
      printf("%d ", c[i]);
    }
    printf("\n");
  }

  return 0;
}