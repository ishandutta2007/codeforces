#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int a[maxn], b[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    b[0] = a[0];
    b[n] = a[n - 1];
    for (int i = 1; i < n; i++) b[i] = lcm(a[i - 1], a[i]);
    bool flg = true;
    for (int i = 0; i < n; i++)
      if (a[i] != gcd(b[i], b[i + 1])) {
        flg = false;
        break;
      }
    puts(flg?"YES":"NO");
  }
  return 0;
}