#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
char t[maxn];
int st;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    st = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        t[st++] = 'a' - 1 + (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        i -= 2;
      } else
        t[st++] = 'a' - 1 + s[i] - '0';
    }
    t[st] = 0;
    reverse(t, t + st);
    printf("%s\n", t);
  }
  return 0;
}