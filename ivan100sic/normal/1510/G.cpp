// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
basic_string<int> e[105], put;
int d[105], p[105];
int mark[105];

void dfs(int x) {
  put += x;
  for (int y : e[x]) {
    if (mark[y]) {
      dfs(y);
      put += x;
    }
  }
}

void solve() {
  cin >> n >> k;

  for (int i=1; i<=n; i++) {
    e[i] = {};
    mark[i] = 0;
  }
  put = {};

  for (int i=2; i<=n; i++) {
    cin >> p[i];
    e[p[i]] += i;
    d[i] = d[p[i]] + 1;
  }

  int mxd = max_element(d+1, d+n+1) - d;
  if (k <= d[mxd] + 1) {
    // moze samo taj put
    int u = mxd;
    for (int i=0; i<d[mxd]+1-k; i++) u = p[u];
    vector<int> sol;
    for (int i=0; i<k; i++) {
      sol.push_back(u);
      u = p[u];
    }
    reverse(begin(sol), end(sol));
    cout << k-1 << '\n';
    for (int x : sol) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }

  // izmarkiraj put i onda dodaj jos cvorova
  int u = mxd;
  while (u) {
    mark[u] = 1;
    u = p[u];
  }

  int cnt = d[mxd] + 1;
  for (int i=1; i<=n; i++) {
    if (cnt < k && !mark[i]) {
      mark[i] = 2;
      cnt++;
    }
  }

  // prebaci teski put na kraj
  for (int i=1; i<=n; i++) {
    partition(begin(e[i]), end(e[i]), [](int x) { return mark[x] != 1; });
  }

  dfs(1);
  put.erase(find(begin(put), end(put), mxd) + 1, put.end());
  cout << put.size() - 1 << '\n';
  for (int x : put) {
    cout << x << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}