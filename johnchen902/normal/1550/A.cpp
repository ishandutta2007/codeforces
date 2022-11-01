#include <stdio.h>

int solve(int x) {
  int ans = 0;
  for (int i = 1; x > 0; x -= i, i += 2)
    ans++;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int s;
    scanf("%d", &s);
    printf("%d\n", solve(s));
  }
}