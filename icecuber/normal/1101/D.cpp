#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];
int a[200000];
int ans = 0;

int dfs(int p, int d, int par = -1) {
  if (a[p]%d) return 0;
  while (a[p]%d == 0) a[p] /= d;
  vector<int> v;
  for (int i : node[p]) {
    if (i == par) continue;
    v.push_back(dfs(i, d, p));
  }
  sort(v.rbegin(), v.rend());
  int r = 1;
  if (v.size()) r += v[0];
  if (v.size()>1) ans = max(ans, r+v[1]);
  ans = max(ans,r);
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 2; j*j <= a[i]; j++) {
      if (a[i]%j) continue;
      dfs(i,j);
    }
    if (a[i] > 1)
      dfs(i,a[i]);
  }
  cout << ans << endl;
}