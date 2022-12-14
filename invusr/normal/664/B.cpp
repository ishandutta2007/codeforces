#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100;

char s[MaxN];

int a[MaxN], b[MaxN];

int main() {
  int k = 0, n, pos = 1, neg = 0;
  while (true) {
    char c;
    scanf(" %c", &c);
    scanf(" %c", &c);

    s[k++] = c;

    if (c == '=') {
      break;
    } else {
      pos += c == '+';
      neg += c == '-';
    }
  }

  scanf("%d", &n);

  if (pos - n * neg > n || n * pos - neg < n) {
    printf("Impossible\n");
    return 0;
  }

  printf("Possible\n");

  int l = 0, r = 0;
  for (int i = 0; i < k; ++i) {
    a[i] = 1;
  }
  if (n <= pos - neg) {
    l = pos - n - neg;
    for (int i = 0; i < k - 1; ++i) {
      if (s[i] == '-') {
        b[r++] = i + 1;
      }
    }
  } else {
    l = n + neg - pos;
    b[r++] = 0;
    for (int i = 0; i < k - 1; ++i) {
      if (s[i] == '+') {
        b[r++] = i + 1;
      }
    }
  }

  int x = 0;
  for (int i = 0; i < l; ++i) {
    x += a[b[x]] == n;
    ++a[b[x]];
  }

  for (int i = 0; i < k; ++i) {
    printf("%d %c ", a[i], s[i]);
  }
  printf("%d\n", n);

  return 0;
}