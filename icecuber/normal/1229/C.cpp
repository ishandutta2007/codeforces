#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans = 0;
ll deg[100000];
vector<int> in[100000];

void query(int p) {
  ll indeg = in[p].size();
  ans -= indeg*(deg[p]-indeg);
  for (int i : in[p]) {
    ll indeg = in[i].size();
    ans -= indeg*(deg[i]-indeg);
    in[i].push_back(p);
    ans += (indeg+1)*(deg[i]-indeg-1);
  }
  in[p].clear();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++, deg[b]++;
    if (a > b)
      in[b].push_back(a);
    else
      in[a].push_back(b);
  }
  for (int i = 0; i < n; i++) {
    ll indeg = in[i].size();
    ans += indeg*(deg[i]-indeg);
  }
  cout << ans << '\n';
  int q;
  cin >> q;
  while (q--) {
    int i;
    cin >> i;
    i--;
    query(i);
    cout << ans << '\n';
  }
}