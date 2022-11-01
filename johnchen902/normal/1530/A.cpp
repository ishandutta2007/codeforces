#include <stdio.h>
#include <string.h>
#include <algorithm>

char s[100];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int ans = *std::max_element(s, strchr(s, '\0')) - '0';
    printf("%d\n", ans);
  }
}