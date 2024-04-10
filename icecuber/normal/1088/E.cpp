#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nax = 3e5;
ll a[nax], dp1[nax];
vector<int> node[nax];

ll ans1 = -1e18, ans2 = 0;
void dfs1(int p, int par = -1) {
  dp1[p] = a[p];
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i,p);
    dp1[p] += max(0ll, dp1[i]);
  }
  ans1 = max(ans1, dp1[p]);
}

void dfs2(int p, int par = -1) {
  dp1[p] = a[p];
  for (int i : node[p]) {
    if (i == par) continue;
    dfs2(i,p);
    dp1[p] += max(0ll, dp1[i]);
  }
  if (dp1[p] == ans1) {
    ans2++;
    dp1[p] = 0;
  }
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
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs1(0);
  dfs2(0);
  cout << ans1*ans2 << ' ' << ans2 << endl;
}