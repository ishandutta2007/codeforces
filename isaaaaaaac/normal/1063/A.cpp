#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 50;

int n, cnt[130];
char s[N];

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i ++) cnt[s[i]] ++;
  for (int i = 0; i < 130; i ++)
    for (int j = 1; j <= cnt[i]; j ++)
      printf("%c", i);
  puts("");
  return 0;
}