#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i);
    int x = 0;
    rep(i, 2, n) x += a[i - 1] == a[i];
    if(x <= 1) puts("0");
    else {
      int l = 0, r = 0;
      rep(i, 2, n) if(a[i - 1] == a[i]) {
        if(!l) l = i;
        r = i;
      }
      printf("%d\n", max(1, r - l - 1));
    }
  }
  return 0;
}