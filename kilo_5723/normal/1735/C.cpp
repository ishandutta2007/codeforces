#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int alpha = 26;
const int maxn = 1e5 + 5;
int nxt[alpha], las[alpha];
char s[maxn];
int find(int u) {
  while (~las[u]) u = las[u];
  for (int i = 0; i < alpha; i++)
    if (i != u && las[i] == -1) return i;
  return u;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    memset(nxt, -1, sizeof(nxt));
    memset(las, -1, sizeof(las));
    int k = 0;
    for (int i = 0; i < n; i++) {
      int u = s[i] - 'a', v = nxt[u];
      if (!~v) {
        v = find(u);
        nxt[u] = v;
        las[v] = u;
      }
      putchar('a' + v);
    }
    puts("");
  }
  return 0;
}