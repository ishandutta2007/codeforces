#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[1000];
int done[1000];
int dfs(int p) {
  if (done[p]++) return 0;
  int r = 1;
  for (int i : node[p]) {
    r += dfs(i);
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> govern(k);
  for (int&v : govern) {
    cin >> v;
    v--;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  ll ma = 0, sum = 0;
  ll ans = 0;
  for (int v : govern) {
    ll sz = dfs(v);
    ans += sz*(sz-1)/2;
    ma = max(ma, sz);
    sum += sz;
  }
  ans -= ma*(ma-1)/2;
  ma += n-sum;
  ans += ma*(ma-1)/2;
  cout << ans-m << endl;
}