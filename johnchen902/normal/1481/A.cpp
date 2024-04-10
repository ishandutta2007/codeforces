#include <cstdio>

using namespace std;

char s[100001];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d%d%s", &x, &y, s);

    int u = 0, d = 0, r = 0, l = 0;
    for (int i = 0; s[i]; i++)
      switch (s[i]) {
        case 'U': u++; break;
        case 'D': d++; break;
        case 'R': r++; break;
        case 'L': l++; break;
      }

    puts(y <= u && y >= -d && x <= r && x >= -l ? "YES" : "NO");
  }
}