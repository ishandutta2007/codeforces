#include <bitset>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e6 + 5;
bitset<maxn> a;
char s[maxn];
bool operator<(bitset<maxn> a, bitset<maxn> b) {
  for (int i = maxn - 1; i >= 0; i--)
    if (a[i] != b[i]) return a[i] < b[i];
  return false;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) a[n - 1 - i] = s[i] - '0';
  while (n && !a[n - 1]) n--;
  // printf("%d\n", n);
  auto ans = a;
  for (int i = 1; i < n; i++) {
    auto tmp = (a >> i) | a;
    // for (int i = n - 1; i >= 0; i--) printf("%d ", (int)tmp[i]);
    // puts("");
    if (ans < tmp) ans = tmp;
    if (s[i] == '0') break;
  }
  if (!n) putchar('0');
  for (int i = n - 1; i >= 0; i--) printf("%d", (int)ans[i]);
  puts("");
  return 0;
}