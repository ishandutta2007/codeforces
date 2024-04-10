#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    int n = h*w;
    vector<int> col(n);
    for (int i = 0; i < h; i++) {
      string row;
      cin >> row;
      for (int j = 0; j < w; j++) {
	col[i*w+j] = row[j]-'0';
      }
    }

    vector<int> par(n);
    vector<vector<int>> child(n);
    for (int i = 0; i < h; i++) {
      string row;
      cin >> row;
      for (int j = 0; j < w; j++) {
	int p = i*w+j, pa;
	if (row[j] == 'L') pa = p-1;
	else if (row[j] == 'R') pa = p+1;
	else if (row[j] == 'U') pa = p-w;
	else if (row[j] == 'D') pa = p+w;
	else assert(0);
	par[p] = pa;
	child[pa].push_back(p);
      }
    }

    vector<int> done(n), d(n,-1);
    int tot = 0, blacks = 0;
    for (int i = 0; i < n; i++) {
      if (done[i]) continue;
      vector<int> node_list;
      int clen = -1;
      function<void(int,int)> dfs = [&](int p, int depth) {
	if (done[p]) {
	  clen = depth;
	  return;
	}
	node_list.push_back(p);
	done[p] = 1;
	d[p] = depth;
	for (int j : child[p]) {
	  dfs(j, depth+1);
	}
      };
      int s = i;
      set<int> seen;
      while (seen.insert(s).second) s = par[s];
      dfs(s,0);
      assert(clen != -1);
      vector<int> black(clen);
      for (int j : node_list) {
	black[d[j]%clen] |= (col[j] == 0);
      }
      tot += clen;
      for (int v : black) blacks += v;
    }
    cout << tot << ' ' << blacks << '\n';
  }
}