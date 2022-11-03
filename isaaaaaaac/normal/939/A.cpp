#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5005;

int f[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d", &f[i]);
  for (int i = 1; i <= n; i ++) {
    if (f[f[f[i]]] == i && f[f[i]] != i) return puts("YES"), 0;
  }
  puts("NO");
  return 0;
}