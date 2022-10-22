#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// At most 7 prime factors

const int nax = 1e6+10;

vector<int> facs(int v) {
  vector<int> r;
  for (int i = 2; i*i <= v; i++) {
    if (v%i == 0) {
      r.push_back(i);
      while (v%i == 0) v /= i; 
    }
  }
  if (v > 1)
    r.push_back(v);
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  vector<vector<int>> node(nax);
  for (int v : a) {
    for (int f : facs(v)) {
      node[f].push_back(v);
      node[v].push_back(f);
    }
  }

  vector<int> col(nax);
  int cols = 1;
  for (int i = 0; i < nax; i++) {
    if (col[i]) continue;
    function<void(int)> dfs = [&](int p) {
      if (col[p]) return;
      col[p] = cols;
      for (int j : node[p]) dfs(j);
    };
    dfs(i);
    cols++;
  }

  set<array<int,2>> joinable;
  for (int v : a) {
    set<int> s;
    for (int f : facs(v+1))
      s.insert(col[f]);
    s.insert(col[v]);
    for (int i : s)
      for (int j : s)
        joinable.insert({i,j});
  }

  while (q--) {
    int ai, bi;
    cin >> ai >> bi;
    int ca = col[a[ai-1]], cb = col[a[bi-1]];
    if (ca == cb) {
      cout << 0 << endl;
    } else if (joinable.count({ca,cb})) {
      cout << 1 << endl;
    } else cout << 2 << endl;
  }
}