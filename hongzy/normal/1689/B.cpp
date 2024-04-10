#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 3e5 + 10;
int n, p[N], q[N];
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", p + i);
    if(n == 1) {
      puts("-1");
      continue ;
    }
    vector<bool> vis(n + 1);
    q[n] = p[n];
    rep(i, 1, n) {
      rep(j, 1, n) if(!vis[j] && j != p[i]) {
        vis[j] = 1; q[i] = j; break ;
      }
    }
    if(q[n] == p[n]) swap(q[n - 1], q[n]);
    rep(i, 1, n) printf("%d%c", q[i], " \n"[i == n]);
  }
  return 0;
}