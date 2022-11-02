#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int alpha = 26;
const int maxn = 5e5 + 5;
ll a[alpha], b[alpha];
bool check() {
  for (int i = 1; i < alpha; i++)
    if (b[i]) return true;
  for (int i = 1; i < alpha; i++)
    if (a[i]) return false;
  return a[0] < b[0];
}
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    while (n--) {
      int d, x;
      scanf("%d%d%s", &d, &x, s);
      for (int i = 0; s[i]; i++) (d == 1 ? a : b)[s[i] - 'a'] += x;
      puts(check()?"YES":"NO");
    }
  }
  return 0;
}