#include <cstdio>

const int N = 1000 + 10;

int n, t[N];
bool flag[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]), flag[t[i]] = true;
  for (int i = 1; i + 2 < N; ++i) if (flag[i] && flag[i + 1] && flag[i + 2]) return puts("YES"), 0;
  puts("NO");
  return 0;
}