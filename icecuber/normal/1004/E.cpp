#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<pair<int,int>> node[nax];

pair<int,int> fur;
int parent[nax];
int dist[nax];
void dfs(int p, int par, int d) {
  if (par == -1) fur = {-1,-1};
  fur = max(fur, make_pair(d, p));
  parent[p] = par;
  dist[p] = d;
  for (auto [i,c] : node[p]) {
    if (i == par) continue;
    dfs(i,p,d+c);
  }
}

void spread(int p) {
  for (auto [i,c] : node[p]) {
    if (dist[i] == -1) {
      dist[i] = dist[p]+c;
      spread(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].emplace_back(b, c);
    node[b].emplace_back(a, c);
  }
  dfs(0, -1, 0);
  dfs(fur.second, -1, 0);
  int p = fur.second;

  vector<int> a, ind;
  while (1) {
    a.push_back(dist[p]);
    ind.push_back(p);
    p = parent[p];
    if (p == -1) break;
  }

  reverse(a.begin(),a.end());
  reverse(ind.begin(),ind.end());
  int mi = 2e9, start = a[0];
  for (int i = 0; i < (int)a.size(); i++) {
    int cost = max(a[i], a.back()-a[min(i+k-1,(int)a.size()-1)]);
    if (cost < mi) {
      mi = cost;
      start = i;
    }
  }

  fill_n(dist, n, -1);
  for (int i = start; i < (int)a.size() && i < start+k; i++)
    dist[ind[i]] = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] == 0)
      spread(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, dist[i]);
  cout << ans << endl;
}