#include <cstdio>
#include <cmath>

int a[1000001];

int main() {
  int i, j;
  a[0] = a[1] = 1;
  for (i = 2; i <= 1000; i++) if (!a[i]) for (j = i * i; j <= 1000000; j += i) a[j] = 1;
  int n;
  scanf("%d", &n);
  while (n--) {
    long long a;
    scanf("%lld", &a);
    long long t = sqrt(a) + .5;
    puts(t * t == a && !::a[t] ? "YES" : "NO");
  }
}