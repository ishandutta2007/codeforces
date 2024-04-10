#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, a[maxn];
int flg[maxn << 1];

void sieve() {
  int N = 400005;
  for (int i = 2; i <= N; i++) {
    if (flg[i]) continue;
    for (int j = i << 1; j <= N; j += i) {
      flg[j] = 1;
    }
  }
  for (int i = 2; i <= N; i++) {
    flg[i] ^= 1;
  }
}

int main() {
  sieve();
  scanf("%d", &n);
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == 1) c1++;
    if (a[i] == 2) c2++;
  }
  int N = c1 + c2 + c2;
  int now = 0;
  while (now <= N && (c1 || c2)) {
    if (flg[now + 1]) {
      if (c1) {
        printf("1 "), now++; c1--;
      } else if (c2) {
        printf("2 "), now += 2, c2--;
      }
    } else {
      if (flg[now + 2]) {
        if (c2) {
          printf("2 "), now += 2; c2--;
        } else if (c1 > 1) {
          printf("1 1 "), now += 2; c1 -= 2;
        } else if (c1 == 1) {
          printf("1 "), now++, c1--;
        }
      } else {
        if (c2) {
          printf("2 "), now += 2; c2--;
        } else if (c1) {
          printf("1 "), now += 1; c1--;
        }
      }
    }
  }
  return 0;
}