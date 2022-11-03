#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 50;

int buc[22], n;
char s[N];

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i ++) buc[s[i] - '0'] ++;
  printf("%d\n", min(n / 11, buc[8]));
  return 0;
}