#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

pair<int,int> f(vector<pair<int,int>>&a, int r0) {
  int r = r0;
  int count = 0;
  for (auto p : a) {
    if (r >= p.x) {
      r += p.y;
      count++;
    }
  }
  return {r,count};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r0;
  cin >> n >> r0;
  vector<pair<int,int>> pos, neg;
  for (int i = 0; i < n; i++) {
    int need, del;
    cin >> need >> del;
    if (del >= 0) pos.push_back({need,del});
    else neg.push_back({need+del,-del});
  }
  sort(pos.begin(), pos.end());
  sort(neg.rbegin(), neg.rend());
  auto top = f(pos, r0);
  vector<int> dp(top.x+1,-1e9);
  dp[top.x] = top.y;
  int ans = top.y;
  for (auto p : neg) {
    int del = p.y, need = p.x+del;
    for (int j = max(need, del); j <= top.x; j++) {
      if (dp[j] != -1e9) {
	dp[j-del] = max(dp[j-del], dp[j]+1);
	ans = max(ans, dp[j]+1);
      }
    }
  }
  cout << ans << endl;
}