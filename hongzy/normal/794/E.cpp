#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
template<class T>
void chkmax(T &x, const T &y) { if(x < y) x = y; }
const int N = 3e5 + 10;
int n, a[N], ans[N];
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i);
  rep(i, 1, n - 1) chkmax(ans[2 * min(i, n - i)], max(a[i], a[i + 1]));
  rep(i, 2, n - 1) chkmax(ans[2 * min(i - 1, n - i) + 1], min(a[i], max(a[i - 1], a[i + 1])));
  chkmax(ans[1], *max_element(a + 1, a + n + 1));
  per(i, n - 2, 2) chkmax(ans[i], ans[i + 2]);
  per(i, n, 1)
    printf("%d%c", ans[i], " \n"[i == 1]);
  return 0;
}