#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e6+10;
vector<int> node[nax];

struct DepthArray {
  vector<int> d;
  pair<int,int> domi;
  int& operator[](int i) {
    return d[d.size()-1-i];
  }
};

int ans[nax];

DepthArray dfs(int p, int par) {
  DepthArray ret;
  ret.domi = {1e9,-1};
  for (int i : node[p]) {
    if (i == par) continue;
    DepthArray a = dfs(i, p);
    if (a.d.size() > ret.d.size()) swap(a, ret);
    for (int i = 0; i < a.d.size(); i++) {
      ret[i] += a[i];
      ret.domi = min(ret.domi, make_pair(ret[i], i));
    }
  }
  ret.d.push_back(-1);
  ret.domi.second++;
  ret.domi = min(ret.domi, make_pair(-1,0));
  ans[p] = ret.domi.second;
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0,-1);
  for (int i = 0; i < n; i++)
    cout << ans[i] << '\n';
}