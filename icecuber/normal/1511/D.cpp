#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  string ans = "a";
  vector<vector<int>> done(k,vector<int>(k));
  vector<int> col(k);
  function<void(int)> dfs = [&](int p) {
    if (col[p]++) return;
    for (int i = 0; i < k; i++) {
      if (!done[p][i]++) {
        done[i][p] = 1;
        ans += 'a'+i;
        if (i != p) {
          dfs(i);
          ans += 'a'+p;
        }
      }
    }
    col[p] = 0;
  };
  while ((int)ans.size() < n) {
    done.assign(k, vector<int>(k));
    dfs(0);
  }
  cout << ans.substr(0,n) << endl;
  
}