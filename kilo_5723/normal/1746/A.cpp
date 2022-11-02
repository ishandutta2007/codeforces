#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 55;
int a[maxn];
bool check(int n) {
  for (int i = 0; i < n; i++)
    if (a[i]) return true;
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int k, n;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    puts(check(n) ? "YES" : "NO");
  }
  return 0;
}