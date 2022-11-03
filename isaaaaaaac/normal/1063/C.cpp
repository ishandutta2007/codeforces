#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 50;

int n, L, R;
char s[100];

int main() {
  scanf("%d", &n);
  L = 0, R = 1e9 - 3000;
  int XMIN = 1e9, YMIN = 1e9;
  for (int i = 1; i <= min(n, 15); i ++) {
    int mid = (L + R) >> 1;
    printf("0 %d\n", mid);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'b') R = mid, XMIN = min(XMIN, mid);
    else L = mid;
  }
  L = 3000;
  R = 1e9 + 3000;
  for (int i = 16; i <= n; i ++) {
    int mid = (L + R) >> 1;
    printf("%d 0\n", mid);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'b') R = mid, YMIN = min(YMIN, mid);
    else L = mid;
  }
  printf("0 %d %d 0\n", XMIN - 1, YMIN - 1);
  fflush(stdout);
  return 0;
}