#include <cstdio>
#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    bool flg = true;
    for (int i = 1; i < n; i++)
      if (a[i] % a[0]) flg = false;
    puts(flg ? "YES" : "NO");
  }
  return 0;
}