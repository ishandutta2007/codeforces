#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int j = lower_bound(dp.begin(), dp.end(),a)-dp.begin();
    if (j == dp.size())
      dp.push_back(a);
    dp[j] = a;
  }
  cout << dp.size() << endl;
}