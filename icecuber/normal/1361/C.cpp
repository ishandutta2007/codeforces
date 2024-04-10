#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int a, b, i, ai, bi;
};

struct V {
  vector<Edge> outs;
};

vector<int> euler(vector<V>& nodes, int nedges, int src) {
  for (auto v : nodes) if (v.outs.size()%2) return {};

  vector<vector<Edge>::iterator> its;
  for (auto&v : nodes)
    its.push_back(v.outs.begin());
  vector<bool> eu(nedges);
  vector<int> ret;
  vector<array<int,3>> s = {{src,0,0}};
  while (!s.empty()) {
    auto [x,ai,bi] = s.back();
    auto& it = its[x], end = nodes[x].outs.end();
    while (it != end && eu[it->i]) ++it;
    if (it == end) {
      ret.push_back(bi);
      ret.push_back(ai);
      s.pop_back();
    } else {
      s.push_back({it->b,it->ai,it->bi});
      eu[it->i] = true;
    }
  }
  //cout << nodes.size() << ' ' << ret.size() <<endl;
  if((int)ret.size() != nedges*2+2) return {};
  ret.pop_back();
  ret.pop_back();
  reverse(ret.begin(), ret.end());
  return ret;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  for (int k = 20; k >= 0; k--) {
    vector<V> node(1<<k);
    int mask = (1<<k)-1, src = 0;
    for (int i = 0; i < n; i++) {
      int x = a[i][0]&mask;
      int y = a[i][1]&mask;
      node[x].outs.push_back({x, y, i, i*2+1, i*2+2});
      node[y].outs.push_back({y, x, i, i*2+2, i*2+1});
      src = x;
    }
    auto ans = euler(node, n, src);
    if (ans.empty()) continue;
    cout << k << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
    /*for (int i = 0; i < n; i++) {
      int ai = ans[i*2+1]-1;
      int bi = ans[(i*2+2)%(n*2)]-1;
      assert(((a[ai/2][ai%2]^a[bi/2][bi%2])&mask) == 0);
      }*/
    return 0;
  }
  assert(0);
}