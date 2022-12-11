#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
int n, a[N], b[N];
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    vector<int> c(n + 1);
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) scanf("%d", b + i);
    bool bo = 0;
    int z = 1;
    rep(i, 1, n) {

      while(1) {
        if(z <= n && b[i] == a[z]) {
          z ++;
          break ;
        } else {
          if(b[i] == b[i - 1] && c[b[i]]) {
            --c[b[i]];
            break ;
          } else {
            if(z > n) { bo = 1; break ; }
            ++c[a[z]];
            z ++;
          }
        }
      }
      if(bo) break ;
      
    }
    rep(i, 1, n) bo |= c[i] > 0;
    puts(bo ? "NO" : "YES");
  }
  return 0;
}