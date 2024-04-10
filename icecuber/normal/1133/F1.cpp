#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];
int done[200000];

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
  int maxdeg = 0, root;
  for (int i = 0; i < n; i++) {
    if (node[i].size() > maxdeg) {
      maxdeg = node[i].size();
      root = i;
    }
  }
  vector<pair<int,int>> ans;
  queue<int> q;
  q.push(root);
  done[root] = 1;
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int i : node[p])
      if (!done[i]++) {
	ans.push_back({p,i});
	q.push(i);
      }
  }
  for (auto p : ans)
    cout << p.first+1 << ' ' << p.second+1 << endl;
}