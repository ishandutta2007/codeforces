#include <stdio.h>
#include <cctype>

const int N = 1000000 + 10;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, k, c[N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) c[i] = nextInt();
  for (int i = 2; i < N; ++i) {
    if (k % i == 0) {
      int cur = 1;
      while (k % i == 0) k /= i, cur *= i;
      for (int j = 1; j <= n; ++j) if (c[j] % cur == 0) goto success;
      puts("No");
      return 0;
   success:
      continue;
    }
  }
  puts("Yes");
  return 0;
}