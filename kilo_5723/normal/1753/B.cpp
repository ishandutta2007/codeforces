#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 5;
int cnt[maxn];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  while (n--) {
    int k;
    scanf("%d", &k);
    cnt[k]++;
    while (cnt[k] == k + 1) {
      cnt[k] = 0;
      cnt[++k]++;
    }
  }
  bool flg = true;
  for (int i = 0; i < x; i++)
    if (cnt[i]) flg = false;
  puts(flg ? "Yes" : "No");
  return 0;
}