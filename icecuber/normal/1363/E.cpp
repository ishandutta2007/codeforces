#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
int cost[nax], cur[nax], target[nax];
vector<int> node[nax];

int needs[nax][2];
ll ans = 0;
void dfs(int p, int par, int min_cost) {
  if (cur[p] != target[p]) {
    needs[p][target[p]]++;
  }
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p, min(min_cost, cost[i]));
    for (int k : {0,1})
      needs[p][k] += needs[i][k];
  }
  int take = min(needs[p][0], needs[p][1]);
  ans += (ll)take*min_cost*2;
  for (int k : {0,1})
    needs[p][k] -= take;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cost[i] >> cur[i] >> target[i];
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0, -1, cost[0]);
  if (needs[0][0] || needs[0][1]) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}