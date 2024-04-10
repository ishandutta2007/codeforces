#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), cnt(n);
    for (int&v : a) cin >> v, cnt[--v]++;
    for (int&v : b) cin >> v, v--;

    int s = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[i] > cnt[s]) s = i;
    }

    vector<vector<int>> node(n), rnode(n);
    for (int i = 0; i < n; i++) {
      if (b[i] == s) continue;
      node[a[i]].push_back(b[i]);
      rnode[b[i]].push_back(a[i]);
    }
    
    vector<int> done(n), topo;
    function<void(int)> dfs = [&](int p) {
      if (done[p]++) return;
      for (int i : node[p]) dfs(i);
      topo.push_back(p);
    };
    for (int i = 0; i < n; i++) dfs(i);
    fill_n(done.begin(), n, 0);
    int cycle = 0;
    //cout << s << ": ";
    for (int p : topo) {
      //cout << p << ' ';
      done[p] = 1;
      for (int i : rnode[p]) if (done[i]) cycle = 1;
    }
    cout << (cycle?"WA":"AC") << endl;
  }
}