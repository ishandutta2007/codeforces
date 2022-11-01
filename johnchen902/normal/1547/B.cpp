#include <stdio.h>
#include <string.h>

bool solve() {
  char s[27];
  scanf("%s", s);
  int n = strlen(s);
  int i = 0, j = n;

  while (n--) {
    if (s[i] == 'a' + n)
      i++;
    else if (s[j - 1] == 'a' + n)
      j--;
    else
      return false;
  }

  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    puts(solve() ? "YES" : "NO");
  }
}