#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
int ans[nax], bdist[nax];

int rem[nax], sz[nax];
void szDfs(int p, int par) {
  sz[p] = 1;
  for (int i : node[p]) {
    if (i == par || rem[i]) continue;
    szDfs(i, p);
    sz[p] += sz[i];
  }
}

int findDfs(int p, int par, int tot) {
  int ma = 0;
  for (int i : node[p]) {
    if (i == par || rem[i]) continue;
    int ret = findDfs(i, p, tot);
    if (ret != -1) return ret;
    ma = max(ma, sz[i]);
  }
  if (ma <= tot/2 && tot-sz[p] <= tot/2) return p;
  return -1;
}

int getCentroid(int p) {
  szDfs(p, -1);
  return findDfs(p, -1, sz[p]);
}


void dq(int p0) {
  int c = getCentroid(p0);
  ans[c] = max(ans[c], bdist[c]);

  int tot = sz[p0];
  vector<int> best(tot);

  vector<vector<int>> vlist(tot);
  function<void(int,int,int)> dfs =
    [&](int p, int d, int par) {
      vlist[d].push_back(p);
      int x = min(bdist[p]-d-1, tot-1);
      if (x >= 0)
        best[x] = max(best[x], bdist[p]);
      for (int i : node[p])
        if (!rem[i] && i != par) dfs(i, d+1, p);
    };
  dfs(c,0,-1);
  for (int i = tot-2; i >= 0; i--) {
    best[i] = max(best[i], best[i+1]);
  }
  for (int d = 0; d < tot; d++) {
    for (int p : vlist[d])
      ans[p] = max(ans[p], best[d]);
  }

  rem[c] = 1;
  for (int i : node[c]) {
    if (!rem[i])
      dq(i);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int k;
  cin >> k;
  fill_n(bdist, n, 1e9);
  queue<int> q;
  for (int i = 0; i < k; i++) {
    int p;
    cin >> p;
    p--;
    q.push(p);
    bdist[p] = 0;
  }

  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int i : node[p]) {
      if (bdist[i] > bdist[p]+1) {
        bdist[i] = bdist[p]+1;
        q.push(i);
      }
    }
  }

  dq(0);
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}