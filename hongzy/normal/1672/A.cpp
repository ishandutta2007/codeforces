#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
int main() {
  int test, n, x;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    int z = 0, x;
    rep(i, 1, n) scanf("%d", &x), z += x - 1;
    puts(z % 2 ? "errorgorn" : "maomao90");
  }
  return 0;
}