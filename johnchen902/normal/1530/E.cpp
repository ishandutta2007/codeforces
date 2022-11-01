#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string.h>

char s[100001];

int go(int i, int n) {
  int j = i + 1;
  while (j < n && s[i] == s[j])
    j++;
  return j;
}

bool solve1(int n) {
  for (int i = 0; i < n; ) {
    int j = go(i, n);

    if (j == i + 1) {
      if (i)
        std::rotate(s, s + i, s + i + 1);
      return true;
    }

    i = j;
  }
  return false;
}

bool solve2a(int n) {
  // a a [no two consecutive a]
  //
  // i.e. a a _ a _ a _ a....
  //    n     3 4 5 6 7
  //    a     2 3 3 4 4

  int a = go(0, n);
  if (a > n / 2 + 1)
    return false;

  for (int i = 2, j = a, k = 2; k < n; k++)
    if (i < a && k % 2)
      s[k] = s[0], i++;
    else
      s[k] = s[j++];
  return true;
}

bool solve2b(int n) {
  // a b a ... a c b ... b

  int a = go(0, n);
  int b = go(a, n);

  if (b != n) {
    // a a ... a b b ... b c
    std::rotate(s + 1, s + a, s + a + 1);
    // a b ... a a b ... b c
    std::rotate(s + a + 1, s + b, s + b + 1);
    // a b ... a a c b ... b
    return true;
  }

  return false;
}

void solve2c(int n) {
  // a b ... b a ... a
  int a = go(0, n);
  std::rotate(s + 1, s + a, s + n);
}

void solve(int n) {
  std::sort(s, s + n);
  if (n == 1) return;
  if (solve1(n)) return;
  if (s[0] == s[n - 1]) return;
  if (solve2a(n)) return;
  if (solve2b(n)) return;
  solve2c(n);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    solve(strlen(s));
    printf("%s\n", s);
  }
}