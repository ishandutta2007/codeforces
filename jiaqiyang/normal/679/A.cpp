#include <cstdio>
#include <cstdlib>

bool check(int x) {
  printf("%d\n", x);
  fflush(stdout);
  static char s[10];
  scanf(" %s", s);
  return s[0] == 'y';
}

const int N = 15, prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

inline void solve(int x) {
  for (int i = 0; i < N; ++i) if (x * prime[i] <= 100 && check(x * prime[i])) puts("composite"), exit(0);
}

int main() {
  if (check(2)) solve(2);
  else if (check(3)) solve(3);
  else if (check(5)) solve(5);
  else if (check(7)) solve(7);
  puts("prime");
  return 0;
}