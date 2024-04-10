#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> ind(n);
  for (int i = 0; i < n*k; i++) {
    int c;
    cin >> c;
    c--;
    ind[c].push_back(i);
  }
  set<int> left;
  for (int i = 0; i < n; i++) left.insert(i);
  vector<array<int,2>> ans(n);
  for (int steps = 0; steps < (n+k-2)/(k-1); steps++) {
    for (int i = 1; i < k && left.size(); i++) {
      array<int,2> best = {int(1e9),-1};
      for (int j : left) {
        best = min(best, array<int,2>{ind[j][i], j});
      }
      int j = best[1];
      left.erase(j);
      ans[j] = {ind[j][i-1], ind[j][i]};
    }
  }
  for (auto [a,b] : ans) cout << a+1 << ' ' << b+1 << endl;

  /*vector<int> covers(n*k);
  for (auto [a,b] : ans) {
    for (int i = a; i <= b; i++)
      covers[i]++;
  }
  assert(*max_element(covers.begin(), covers.end()) <= (n+k-2)/(k-1));*/
}