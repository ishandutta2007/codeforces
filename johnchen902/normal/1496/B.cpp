#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  sort(a, a + n);
  int mex = 0;
  for (; mex < n && a[mex] == mex; mex++)
    ;
  int max = a[n - 1];
  if (mex > max)
    return n + k;
  else if (k == 0 || binary_search(a, a + n, (mex + max + 1) / 2))
    return n;
  else
    return n + 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    printf("%d\n", solve());
}