#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> branches(k);
  for (int i = 0; i < k; ++i) {
    branches[i].push_back(1);
  }
  int current = 0;
  for (int i = 2; i <= n; ++i) {
    branches[current].push_back(i);
    ++current %= k;
  }

  cout << branches[0].size() + branches[1].size() - 2 << endl;
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < branches[i].size(); ++j) {
      cout << branches[i][j - 1] << ' ' << branches[i][j] << endl;
    }
  }

  return 0;
}