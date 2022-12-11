#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
struct node { int u, v, w; };
int L, R, k, n;
vector<node> ans;
int main() {
  scanf("%d%d", &L, &R);
  R -= L - 1;
  per(i, 30, 0) if(R >> i & 1) { k = i; break ; }
  n = k + 3;
  //start, represent 2^k, 2^{k-1}, ..,  2^0, end
  rep(i, 2, k + 2) rep(j, i + 1, k + 2) ans.pb({i, j, 1 << (k + 2 - j)});
  rep(i, 2, k + 2) ans.pb({i, k + 3, 1});
  ans.pb({1, k + 3, 1});
  int z = 1; R --;
  per(i, k, 0) if(R >> i & 1) { //[z+1,z+2^i-1]
    ans.pb({1, k + 2 - i, z});
    z += 1 << i;
  }
  if(L > 1) { ans.pb({n, n + 1, L - 1}); n ++; }
  printf("YES\n%d %lu\n", n, ans.size());
  for(auto x : ans) printf("%d %d %d\n", x.u, x.v, x.w);
  return 0;
}