#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());

  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<vector<int>> adj(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) adj[i][j] = s[j]-'0';
  }

  vector<int> ans;

  for (int it = 0; it < 50; it++) {
    int base = mrand()%n;
    vector<int> ind;
    for (int j = 0; j < m; j++) 
      if (adj[base][j]) ind.push_back(j);

    int k = ind.size();
    vector<int> cnt(1<<k);
    for (int i = 0; i < n; i++) {
      int bit = 0;
      for (int j = 0; j < k; j++)
        bit |= adj[i][ind[j]]<<j;
      cnt[bit]++;
    }
    for (int j = 0; j < k; j++) {
      for (int i = (1<<k)-1; i >= 0; i--) 
        if ((i>>j&1) == 0)
          cnt[i] += cnt[i|1<<j];
    }
    for (int i = 0; i < 1<<k; i++) {
      if (cnt[i] >= (n+1)/2 && __builtin_popcount(i) > (int)ans.size()) {
        ans.clear();
        for (int j = 0; j < k; j++)
          if (i>>j&1) ans.push_back(ind[j]);
      }
    }
  }

  string outs(m, '0');
  for (int i : ans) outs[i] = '1';
  cout << outs << endl;
}