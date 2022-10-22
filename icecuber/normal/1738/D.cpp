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
    vector<vector<int>> in(n+2), out(n+2);
    int k = 0;
    vector<int> sz(n+2);
    for (int a = 1; a <= n; a++) {
      int b;
      cin >> b;
      k = max(k, min(a,b));
      out[a].push_back(b);
      in[b].push_back(a);
      sz[b]++;
    }
    for (int i = 0; i < n+2; i++) {
      sort(in[i].begin(), in[i].end(), [&](int a, int b) {
          return sz[a] < sz[b];
        });
    }
    vector<int> ans = {-1};
    function<void(int)> dfs = [&](int p) {
      ans.push_back(p);
      for (int i : in[p]) dfs(i);
    };
    for (int s : {0,n+1}) {
      for (int i : in[s]) dfs(i);
    }
    cout << k << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
  }
}