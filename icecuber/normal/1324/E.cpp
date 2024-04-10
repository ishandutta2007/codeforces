#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> dp(h, -1e9);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vector<int> ndp(h, -1e9);
    for (int j = 0; j < h; j++)
      for (int k : {(j+a-1)%h,(j+a)%h})
	ndp[k] = max(ndp[k], dp[j]+(k >= l && k <= r));
    swap(dp, ndp);
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}