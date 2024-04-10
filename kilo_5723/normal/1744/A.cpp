#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 55;
char s[maxn];
int a[maxn];
bool check(int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i] == a[j] && s[i] != s[j]) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%s", s);
    puts(check(n) ? "YES" : "NO");
  }
  return 0;
}