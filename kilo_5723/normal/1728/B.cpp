#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 105;
int a[maxn];
bool check(int a[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    if (sum < a[i])
      sum += a[i];
    else
      sum = 0;
  return sum;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n - 1; i++) a[i - 2] = i;
    a[n - 3] = 1;
    a[n - 2] = n - 1;
    a[n - 1] = n;
    while (!check(a, n - 3)) random_shuffle(a, a + n - 3);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}