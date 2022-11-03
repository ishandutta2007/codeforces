#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 50;

char s[N];
int n;

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int tot = 0;
  for (int i = 1; i <= n; i ++) tot += (s[i] == '1');
  for (int i = 1; i <= n; i ++) {
    if (s[i] == '1') continue;
    if (s[i] == '2') {
      for (; tot; tot --) putchar('1');
    }
    putchar(s[i]);
  }
  for (; tot; tot --) putchar('1');
  return 0;
}