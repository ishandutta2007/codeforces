#include <cstdio>
#include <list>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 10;

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int t = a[0];
  for (int i = 1; i < n; ++i) t = gcd(t, a[i]);
  if (t & 1) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += a[i] & 1;
    if (cnt > 1) {
      puts("0");
      for (int i = 0; i < n; ++i) while (a[i]--) putchar('a' + i);
      putchar('\n');
      return 0;
    }
  }
  printf("%d\n", t);
  std::list<char> ans;
  for (int i = 0; i < n; ++i) a[i] /= t;
  for (int i = 0; i < n; ++i) if (a[i] & 1) --a[i], ans.push_back(i);
  for (int i = 0; i < n; ++i) for (int j = a[i] / 2; j--;) ans.push_back(i), ans.push_front(i);
  for (int i = t; i--;) {
    if (i & 1) {
      for (std::list<char>::iterator it = ans.begin(); it != ans.end(); ++it) putchar('a' + *it);
    } else {
      for (std::list<char>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) putchar('a' + *it);
    }
  }
  putchar('\n');
  return 0;
}