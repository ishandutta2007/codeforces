#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int M = 1e6;
template<class T>
struct BIT {
  vector<T> c;
  int n;
  BIT(int sz) { c.resize(1 + (n = sz)); }
  void add(int x, T y) {
    for(; x <= n; x += x & (-x))
      c[x] += y;
  }
  T qry(int x) {
    T ans = 0;
    for(; x >= 1; x &= x - 1)
      ans += c[x];
    return ans;
  }
};
int n, m;
vector<int> lx[M + 5], rx[M + 5];
vector<int> add[M + 5], del[M + 5];
ll ans = 1;
int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, n) {
    int y, l, r;
    scanf("%d%d%d", &y, &l, &r);
    if(l == 0) lx[y].pb(r);
    else rx[y].pb(l);
  }
  BIT<int> bit(M);
  rep(i, 1, m) {
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r);
    if(l == 0) del[r + 1].pb(x), bit.add(x, 1), ans += r == M;
    else add[l].pb(x);
  }
  rep(i, 1, M - 1) {
    for(int u : add[i]) bit.add(u, 1);
    for(int u : del[i]) bit.add(u, -1);
    for(int u : lx[i]) {
      ans += (u == M) + bit.qry(u);
    }
    for(int u : rx[i]) {
      ans += bit.qry(M) - bit.qry(u - 1);
    }
  }
  printf("%lld\n", ans);
  return 0;
}