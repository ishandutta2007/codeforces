#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
int done[nax];

int cycle(int p) {
  if (done[p]++) return 1;
  int ok = node[p].size() == 2;
  for (int i : node[p])
    ok &= cycle(i);
  return ok;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    ans += cycle(i);
  }
  cout << ans << endl;
}