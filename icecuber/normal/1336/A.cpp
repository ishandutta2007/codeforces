#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
int sz[nax];

vector<int> scores;
void dfs(int p, int par, int d) {
  sz[p] = 1;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,p,d+1);
    sz[p] += sz[i];
  }
  scores.push_back(d-(sz[p]-1));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0,-1,0);
  sort(scores.rbegin(), scores.rend());
  ll ans = 0;
  for (int i = 0; i < k; i++)
    ans += scores[i];
  cout << ans << endl;
}