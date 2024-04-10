#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, top;
long long a[200000];

inline long long sum(long long x) {return x * (x - 1) / 2;}


int main() {
  scanf("%d", &n);
  for (int i = 1; i * i <= n; i ++)
    if (n % i == 0) {
      a[++ top] = sum(n / i) * i + n / i;
      if (i * i != n)
        a[++ top] = sum(i) * n / i + i;
    }
  sort(a + 1, a + top + 1);
  for (int i = 1; i <= top; i ++) printf("%lld ", a[i]);
  puts("");
  return 0;
}