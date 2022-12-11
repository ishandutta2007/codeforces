#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
const int INF = 2e9 + 5;
int n, w, a[N], b[N], res[N];
ll ans;
struct node {
  int p, v;
  bool operator < (const node &b) const { return v > b.v; }
};
priority_queue<node> q01, q12, q02, q10, q21;
int main() {
  scanf("%d%d", &n, &w);
  rep(i, 1, n) scanf("%d%d", a + i, b + i);
  rep(i, 1, n) q01.push({i, a[i]}), q02.push({i, b[i]});
  #define L(q) q.push({0, INF})
  L(q01); L(q12); L(q02); L(q10); L(q21);
  ll arr[4];
  rep(i, 1, w) {
    while(q01.size() > 1 && res[q01.top().p] != 0) q01.pop();
    while(q12.size() > 1 && res[q12.top().p] != 1) q12.pop();
    while(q02.size() > 1 && res[q02.top().p] != 0) q02.pop();
    while(q10.size() > 1 && res[q10.top().p] != 1) q10.pop();
    while(q21.size() > 1 && res[q21.top().p] != 2) q21.pop();
    arr[0] = q01.top().v;
    arr[1] = q12.top().v;
    arr[2] = (ll)q02.top().v + q10.top().v;
    arr[3] = (ll)q02.top().v + q21.top().v;
    int x = min_element(arr, arr + 4) - arr, u, v;
    ans += arr[x];
    if(x == 0) {
      res[u = q01.top().p] = 1;
      q12.push({u, b[u] - a[u]});
      q10.push({u, -a[u]});
    }
    if(x == 1) {
      res[u = q12.top().p] = 2;
      q21.push({u, -b[u] + a[u]});
    }
    if(x == 2) {
      res[u = q02.top().p] = 2;
      res[v = q10.top().p] = 0;
      q21.push({u, -b[u] + a[u]});
      q01.push({v, a[v]});
      q02.push({v, b[v]});
    }
    if(x == 3) {
      res[u = q02.top().p] = 2;
      res[v = q21.top().p] = 1;
      q21.push({u, -b[u] + a[u]});
      q10.push({v, -a[v]});
      q12.push({v, b[v] - a[v]});
    }
  }
  printf("%lld\n", ans);
  rep(i, 1, n) printf("%d", res[i]);
  puts("");
  return 0;
}