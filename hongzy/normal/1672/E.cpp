#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
int query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  scanf("%d", &x);
  return x;
}
int main() {
  int n;
  scanf("%d", &n);
  int l = n, r = n * 2001, S = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(query(mid) == 1) r = (S = mid) - 1;
    else l = mid + 1;
  }
  // cout << "S = " << S << endl;
  int res = S;
  rep(i, 1, n) {  
    int w = S / i;
    if(query(w) == i)
      res = min(res, i * w);
  }
  printf("! %d\n", res);
  return 0;
}