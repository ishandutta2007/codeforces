#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
int n, q, s1[N], s0[N];
char s[N];
int main() {
  scanf("%d%d%s", &n, &q, s + 1);
  rep(i, 2, n) s1[i] = s1[i - 1] + (s[i] == '1' && s[i - 1] == '1');
  rep(i, 2, n) s0[i] = s0[i - 1] + (s[i] == '0' && s[i - 1] == '0');
  rep(T, 1, q) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", max(s1[r] - s1[l], s0[r] - s0[l]) + 1);
  }
  return 0;
}