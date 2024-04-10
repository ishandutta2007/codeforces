#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 4e5 + 5, alpha = 3;
char s[maxn];
int dis[alpha];
int id(char ch) {
  switch (ch) {
    case 'r':
      return 0;
    case 'y':
      return 1;
    case 'g':
      return 2;
  }
  return -1;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, c;
    scanf("%d%s", &n, s);
    c = id(s[0]);
    memset(dis, 0, sizeof(dis));
    dis[id('g')] = 0;
    scanf("%s", s);
    memcpy(s + n, s, sizeof(s[0]) * n);
    // printf("%s\n", s);
    int cur = -maxn;
    for (int i = 2 * n; i; i--) {
      if (s[i] == 'g')
        cur = 0;
      else
        cur++;
      dis[id(s[i])] = max(dis[id(s[i])], cur);
    }
    printf("%d\n", dis[c]);
  }
  return 0;
}