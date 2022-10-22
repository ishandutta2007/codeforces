#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,int> idi;
multiset<int> node[200000];
vector<int> tour;
void dfs(int p) {
  while (node[p].size()) {
    int n = *node[p].begin();
    node[p].erase(node[p].find(n));
    node[n].erase(node[n].find(p));
    //cout << idi[p] << ' ' << idi[n] << endl;
    dfs(n);
  }
  tour.push_back(p);
}

int b[100000], c[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> id;
  int ids = 0;
  for (int i = 0; i < n-1; i++)
    cin >> b[i];
  for (int i = 0; i < n-1; i++) {
    cin >> c[i];
    if (c[i] < b[i]) {
      cout << -1 << endl;
      return 0;
    }
    if (!id.count(b[i])) id[b[i]] = ids++;
    if (!id.count(c[i])) id[c[i]] = ids++;
    int u = id[b[i]], v = id[c[i]];
    node[u].insert(v);
    node[v].insert(u);
  }
  for (auto p : id)
    idi[p.second] = p.first;
  vector<int> odds;
  for (int i = 0; i < ids; i++) {
    if (node[i].size()%2)
      odds.push_back(i);
  }
  if (odds.size() && odds.size() != 2) {
    cout << -1 << endl;
    return 0;
  }
  int start = 0;
  if (odds.size())
    start = odds[0];

  dfs(start);
  if (tour.size() != n) {
    cout << -1 << endl;
    return 0;
  }
  for (int i : tour)
    cout << idi[i] << ' ';
  cout << endl;
}