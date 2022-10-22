#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FAIL { cout << "NO" << endl; return; }

void testCase() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> node(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  vector<int> stack, cycle, depth(n, -1);
  function<bool(int,int)> dfs1 = [&](int p, int d) {
    if (depth[p] != -1) {
      if ((d-depth[p])%2) {
        for (int i = depth[p]; i < d; i++)
          cycle.push_back(stack[i]);
        return true;
      }
      return false;
    }
    depth[p] = d;
    stack.push_back(p);
    for (int i : node[p]) {
      if (dfs1(i,d+1)) return true;
    }
    stack.pop_back();
    return false;
  };

  int cycles = 0;
  for (int i = 0; i < n; i++) {
    if (depth[i] != -1) continue;
    if (dfs1(i,0)) {
      cycles++;
      break;
    }
  }

  if (!cycles) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      cout << depth[i]%2;
    cout << endl;
    return;
  }

  vector<int> cyclei(n, -1);
  int k = cycle.size();
  assert(k%2);
  for (int i = 0; i < k; i++) {
    int a = cycle[i], b = cycle[(i+1)%k];
    node[a].erase(find(node[a].begin(), node[a].end(), b));
    node[b].erase(find(node[b].begin(), node[b].end(), a));
    cyclei[a] = i;
  }

  vector<int> col(n, -1);
  vector<vector<int>> group;
  function<bool(int,int)> dfs2 = [&](int p, int c) {
    if (col[p] != -1) {
      if (col[p] != c) return true;
      return false;
    }
    if (cyclei[p] != -1) group.back().push_back(cyclei[p]);
    col[p] = c;
    for (int i : node[p])
      if (dfs2(i,!c)) return true;
    return false;
  };
  for (int i : cycle) {
    if (col[i] != -1) continue;
    group.push_back({});
    if (dfs2(i,0)) FAIL;
  }

  vector<int> bad(k+1);
  for (vector<int> g : group) {
    sort(g.begin(), g.end());
    int l = g.size();
    for (int i = 0; i < l; i++) {
      int a = g[i], b = g[(i+1)%l];
      if (a > b) swap(a,b);
      if ((b-a)%2 != (col[cycle[a]]^col[cycle[b]])) {
        bad[0]++;
        bad[a]--;
        bad[b]++;
        bad[k]--;
      } else {
        bad[a]++;
        bad[b]--;
      }
    }
  }
  int both = -1;
  for (int i = 0; i < k; i++) {
    bad[i+1] += bad[i];
    if (!bad[i]) both = i;
  }
  if (both == -1) FAIL;

  for (int i = 0; i < k; i++) {
    if (i == both) continue;
    int a = cycle[i], b = cycle[(i+1)%k];
    node[a].push_back(b);
    node[b].push_back(a);
  }

  group.clear();
  fill_n(col.begin(), n, -1);
  fill_n(cyclei.begin(), n, -1);
  assert(!dfs2(cycle[both],1));
  assert(!dfs2(cycle[(both+1)%k],1));
  for (int i = 0; i < n; i++) { 
    if (col[i] != -1) continue;
    assert(!dfs2(i,0));
  }

  cout << "YES" << endl;
  for (int c : col) cout << c;
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) testCase();
}