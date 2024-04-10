#include <cstdio>
#include <algorithm>

#define x first
#define y second

typedef std::pair<int, int> Info;

const int N = 200 + 10;

int n;
char s[N];
Info pos[N];

int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; ++i) {
    pos[i] = pos[i - 1];
    if (s[i] == 'U') ++pos[i].y;
    else if (s[i] == 'D') --pos[i].y;
    else if (s[i] == 'L') --pos[i].x;
    else if (s[i] == 'R') ++pos[i].x;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      if (pos[i - 1] == pos[j]) ++ans;
  printf("%d\n", ans);
  return 0;
}