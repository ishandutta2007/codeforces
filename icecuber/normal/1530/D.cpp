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
    vector<int> par(n, -1), child(n);
    vector<int> indeg(n);
    for (int i = 0; i < n; i++) {
      cin >> child[i];
      child[i]--;
      indeg[child[i]]++;
    }
    vector<array<int,2>> order;
    for (int i = 0; i < n; i++) order.push_back({indeg[i], i});
    sort(order.rbegin(), order.rend());
    for (auto [in,i] : order) {
      par[child[i]] = i;
    }
    auto cp = child;
    vector<array<int,2>> chain;
    for (int i = 0; i < n; i++) {
      if (par[i] == -1) {
        int p = i;
        while (par[child[p]] == p) p = child[p];
        chain.push_back({i, p});
      }
    }
    int ans = n;
    for (int i = 0; i < (int)chain.size(); i++) {
      int j = (i+1)%(int)chain.size();
      ans--;
      child[chain[i][1]] = chain[j][0];
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
      cout << child[i]+1 << ' ';
      ans -= (child[i] == cp[i]);
      assert(child[i] != i);
    }
    cout << endl;
    assert(ans == 0);
  }
}