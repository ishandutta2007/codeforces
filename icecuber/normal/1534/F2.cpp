#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> board(h);
  for (string&s : board) cin >> s;

  int n = 0;
  map<array<int,2>,int> id;
  vector<vector<int>> node;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') {
        id[{i,j}] = n++;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') {
        vector<int> nbr;
        if (i && board[i-1][j] == '#') 
          nbr.push_back(id[{i-1,j}]);

        int l = j > 0, r = j+1 < w;
        for (int k = i; k < h; k++) {
          if (k > i && board[k][j] == '#') {
            nbr.push_back(id[{k,j}]);
            break;
          }
          if (l && board[k][j-1] == '#')
            nbr.push_back(id[{k,j-1}]), l = 0;
          if (r && board[k][j+1] == '#')
            nbr.push_back(id[{k,j+1}]), r = 0;
        }
        node.push_back(nbr);
      }
    }
  }
  vector<vector<int>> rnode(n);
  for (int i = 0; i < n; i++)
    for (int j : node[i])
      rnode[j].push_back(i);

  vector<int> topo, done1(n);
  function<void(int)> dfs1 = [&](int p) {
    if (done1[p]++) return;
    for (int i : node[p]) dfs1(i);
    topo.push_back(p);
  };
  for (int i = 0; i < n; i++) dfs1(i);
  reverse(topo.begin(), topo.end());

  vector<int> comp(n), done2(n);
  int comps = 0;
  function<void(int)> dfs2 = [&](int p) {
    if (done2[p]++) return;
    for (int i : rnode[p]) dfs2(i);
    comp[p] = comps;
  };

  for (int p : topo) {
    if (done2[p]) continue;
    dfs2(p);
    comps++;
  }

  vector<int> X(n);
  for (auto [p,i] : id)
    X[i] = p[1];

  vector<int> L(comps, w), R(comps, -1);
  for (int i : topo) {
    L[comp[i]] = min(L[comp[i]], X[i]);
    R[comp[i]] = max(R[comp[i]], X[i]);
    for (int j : node[i]) {
      L[comp[j]] = min(L[comp[j]], L[comp[i]]);
      R[comp[j]] = max(R[comp[j]], R[comp[i]]);
    }
  }

  vector<int> A(w);
  for (int&v : A) cin >> v;

  vector<array<int,2>> inv;
  for (int j = 0; j < w; j++) {
    for (int i = h-1; i >= 0; i--) {
      if (board[i][j] == '#') {
        if (--A[j] == 0) {
          int c = comp[id[{i,j}]];
          inv.push_back({R[c],L[c]});
          break;
        }
      }
    }
  }
  sort(inv.begin(), inv.end());
  int ans = 0, last = -1;
  for (auto [r,l] : inv) {
    if (l > last) ans++, last = r;
  }
  cout << ans << endl;
}