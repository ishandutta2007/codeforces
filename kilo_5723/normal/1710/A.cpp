#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn];
bool check(int n, int m, int k) {
  ll sum = 0;
  bool flg = false;
  for (int i = 0; i < k; i++) {
    if (a[i] / m > 1) sum += a[i] / m;
    if (a[i] / m > 2) flg = true;
  }
  return sum >= n && (flg || n % 2 == 0);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) scanf("%d", &a[i]);
    puts(check(n, m, k) || check(m, n, k) ? "Yes" : "No");
  }
  return 0;
}