#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

array<int,2> par[52][1<<10];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (string&s : a) cin >> s;
    int id[256];
    fill_n(id, 256, -1);
    string alphabet;
    int ids = 0;
    for (string s : a) 
      for (char c : s) 
        if (id[(int)c] == -1) {
          alphabet += c;
          id[(int)c] = ids++;
        }

    vector<vector<vector<int>>> inds(ids+1);
    for (int i = 0; i < ids; i++)
      inds[i].resize(n);

    for (int i = 0; i < n; i++) {
      inds[i].push_back({});
      for (int j = 0; j < (int)a[i].size(); j++) {
        inds[id[(int)a[i][j]]][i].push_back(j);
      }
    }
    inds[ids].resize(n);
    for (int i = 0; i < n; i++) {
      inds[ids][i].push_back(a[i].size());
    }

    vector<vector<int>> mem(ids+1, vector<int>(1<<n, -1));
    function<int(int,int)> dfs = [&](int c, int mask) {
      int&memo = mem[c][mask];
      if (memo == -1) {
        //cout << c << ' ' << mask << endl;
        par[c][mask] = {-1, -1};
        int best = 0;
        for (int p = 0; p < ids; p++) {
          int pmask = 0;
          int ok = 1;
          for (int i = 0; i < n; i++) {
            int k = -1;
            while (k+1 < (int)inds[p][i].size() && inds[p][i][k+1] < inds[c][i][(mask>>i&1)]) k++;
            if (k == -1) {
              ok = 0;
              break;
            }
            pmask |= k<<i;
          }
          if (ok) {
            int score = dfs(p, pmask)+1;
            if (score > best) {
              best = score;
              par[c][mask] = {p, pmask};
            }
          }
        }
        memo = best;
      }
      return memo;
    };
    cout << dfs(ids, 0) << endl;
    {
      int c = ids, mask = 0;
      string path;
      while (c != -1) {
        auto [p, pmask] = par[c][mask];
        c = p, mask = pmask;
        if (c != -1)
          path += alphabet[c];
      }
      reverse(path.begin(), path.end());
      cout << path << endl;
    }
  }
}