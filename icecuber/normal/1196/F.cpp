#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
const int nax = 2e5;
vector<pair<ll,int>> node[nax];
set<pair<int,int>> done;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].push_back({c,b});
    node[b].push_back({c,a});
  }
  priority_queue<tuple<ll,int,int>> pq;
  for (int i = 0; i < n; i++) {
    sort(node[i].begin(), node[i].end());
    node[i].resize(min((int)node[i].size(), k));
    for (auto p : node[i]) {
      if (p.y > i)
	pq.push({-p.x, i,p.y});
    }
  }
  while (pq.size()) {
    ll w;
    int a,b;
    tie(w,a,b) = pq.top();
    pq.pop();
    if (a == b || done.count({a,b})) continue;
    done.insert({a,b});
    w = -w;
    if (--k == 0) {
      cout << w << endl;
      return 0;
    }
    for (auto p : node[a]) {
      pq.push({-(w+p.x), min(p.y,b),max(p.y,b)});
    }
    for (auto p: node[b]) {
      pq.push({-(w+p.x), min(p.y,a),max(p.y,a)});
    }
  }
  assert(0);
}