#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
char s[N];
int n;
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if(s[n] == 'A') { puts("NO"); continue ; }
    int A = 0, tag = 0;
    rep(i, 1, n) {
      if(s[i] == 'A') {
        A++;
      } else {
        A --;
        if(A < 0) { tag = 1; break ; }
      }
    }
    puts(tag ? "NO" : "YES");
  }
  return 0;
}