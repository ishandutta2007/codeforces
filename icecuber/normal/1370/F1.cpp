#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e3;
vector<int> node[nax];

pair<int,int> query(vector<int> v) {
  cout << "? " << v.size();
  for (int i : v) cout << ' ' << i+1;
  cout << endl;
  int x, d;
  cin >> x >> d;
  if (x == -1 && d == -1) exit(0);
  return {x-1,d};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) node[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    vector<int> all;
    for (int i = 0; i < n; i++) all.push_back(i);
    auto [root, ABdist] = query(all);

    vector<int> parent(n);
    vector<vector<int>> atdepth;
    function<void(int,int,int)> dfs = [&](int p, int par, int d) {
      parent[p] = par;
      while ((int)atdepth.size() <= d) atdepth.push_back({});
      atdepth[d].push_back(p);
      for (int i : node[p]) {
	if (i == par) continue;
	dfs(i, p, d+1);
      }
    };
    dfs(root, -1, 0);

    int pass = 0, fail = atdepth.size();
    int A = -1, B = -1;
    while (fail-pass > 1) {
      int mid = (pass+fail)/2;
      auto [x, d] = query(atdepth[mid]);
      if (d == ABdist) {
	A = x;
	pass = mid;
      } else fail = mid;
    }

    int Bdepth = ABdist-pass;
    int Astart = A;
    for (int i = 0; i < pass-1; i++)
      Astart = parent[Astart];

    atdepth.resize(1);
    for (int i : node[root]) {
      if (i != Astart)
	dfs(i, root, 1);
    }
    int ABdist_;
    tie(B, ABdist_) = query(atdepth[Bdepth]);
    assert(ABdist == ABdist_);

    cout << "! " << A+1 << ' ' << B+1 << endl;
    string verdict;
    cin >> verdict;
    if (verdict == "Incorrect") return 0;
  }
}