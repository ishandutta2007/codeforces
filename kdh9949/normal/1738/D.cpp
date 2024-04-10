#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> pmn(n + 2), smx(n + 2);
  pmn[0] = n + 1;
  smx[n + 1] = 0;
  for(int i = 1; i <= n; ++i) pmn[i] = min(pmn[i - 1], a[i]);
  for(int i = n; i >= 1; --i) smx[i] = max(smx[i + 1], a[i]);

  int k;
  for(k = 0; k <= n; ++k) {
    if(pmn[k] > k && smx[k + 1] <= k) break;
  }

  vector<int> e(n + 2, -1);
  vector<vector<int>> l(n + 2);
  for(int i = 1; i <= n; ++i) {
    if(1 <= a[i] && a[i] <= n) e[a[a[i]]] = a[i];
    l[a[i]].push_back(i);
  }

  //for(int i = 0; i <= n + 1; ++i) cout << e[i] << ' ';
  //cout << '\n';

  cout << k << '\n';
  int cur = (e[0] < 0 ? n + 1 : 0);
  if(e[cur] < 0) {
    for(int i = 1; i <= n; ++i) cout << i << ' ';
    cout << '\n';
    return;
  }
  while(e[cur] >= 0) {
    for(int x : l[cur]) if(x != e[cur]) cout << x << ' ';
    cout << e[cur] << ' ';
    cur = e[cur];
  }
  for(int x : l[cur]) cout << x << ' ';
  cout << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) { solve(); }

  return 0;
}