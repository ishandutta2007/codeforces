#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
char s[N];
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    int n;
    scanf("%d%s", &n, s + 1);
    int z = 0, m = (n + 1) / 2;
    if(n & 1) {
      rep(i, m + 1, n) {
        if(s[i] != s[m]) break ;
        z ++;
      }
      z = z * 2 + 1;
    } else {
      rep(i, m + 1, n) {
        if(s[i] != s[m]) break ;
        z ++;
      }
      z = z * 2;
    }
    printf("%d\n", z);
  }
  return 0;
}