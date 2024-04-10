#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 21;

int cnt[1 << N];

int main() {
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    char op, s[30];
    scanf(" %c %s", &op, s);
    int t = strlen(s);
    std::reverse(s, s + t);
    int cur = 0;
    for (int i = 0; i < t; ++i) if ((s[i] - '0') & 1) cur |= 1 << i;
    if (op == '+') {
      ++cnt[cur];
    } else if (op == '-') {
      --cnt[cur];
    } else {
      printf("%d\n", cnt[cur]);
    }
  }
  return 0;
}