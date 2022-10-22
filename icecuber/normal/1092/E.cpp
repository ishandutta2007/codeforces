#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[1000];
int done[1000];
int par[1000];
int furthest, maxdist;

void dfs(int p, int col, int dist = 0) {
  if (done[p] == col) return;
  done[p] = col;
  if (dist > maxdist) {
    maxdist = dist;
    furthest = p;
  }
  for (int i : node[p]) {
    if (i == par[p]) continue;
    par[i] = p;
    dfs(i,col,dist+1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int maxdiameter = 0;
  vector<pair<int, int>> centroid;
  for (int i = 0; i < n; i++) {
    if (done[i] == 2) continue;
    maxdist = -1;
    dfs(i,1);
    maxdist = -1;
    par[furthest] = -1;
    dfs(furthest,2);
    int c = furthest;
    for (int i = 0; i < maxdist/2; i++)
      c = par[c];
    maxdiameter = max(maxdiameter, maxdist);
    centroid.push_back({maxdist+1>>1,c});
  }
  sort(centroid.rbegin(), centroid.rend());
  int ans = maxdiameter;
  if (centroid.size() > 1)
    ans = max(ans, centroid[0].first+centroid[1].first+1);
  if (centroid.size() > 2)
    ans = max(ans, centroid[1].first+centroid[2].first+2);
  cout << ans << endl;
  for (int i = 1; i < centroid.size(); i++)
    cout << centroid[i].second+1 << ' ' << centroid[0].second+1 << '\n';
}