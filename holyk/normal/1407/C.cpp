#include <cstdio>

inline int ask(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  int x;
  scanf("%d",  &x);
  return x;
}
int n, ans[10004];
int main() {
  scanf("%d", &n);
  int max = 1;
  for (int i = 2; i <= n; i++) {
    int a = ask(max, i), b = ask(i, max);
    if (a > b) {
      ans[max] = a;
      max = i;
    } else {
      ans[i] = b;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!ans[i]) {
      max = i;
      break;
    }
  }
  if (!ans[max]) {
    ans[max] = max;
    for (int i = 1; i <= n; i++)
      if (i != max)
        ans[max] += i - ans[i];
  }
  putchar('!');
  for (int i = 1; i <= n; i++)
    printf(" %d", ans[i]);
  return 0;
}