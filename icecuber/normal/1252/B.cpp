#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+10;
int dp[nax][2];
int a[nax];
int n, m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  a[m] = -1;

  map<int,int> left, right;
  auto add = [&](int i) {
    left[a[i]+i] = i;
    right[a[i]-i] = i;
  };
  add(m-1);

  auto Left = [&](int p, int t) {
    if (left.count(t+(p-1)))
      return dp[left[t+(p-1)]][0];
    else
      return p-(m+1-t);
  };
  auto Right = [&](int p, int t) {
    if (right.count((p+1)-t))
      return dp[right[(p+1)-t]][1];
    else
      return p+(m+1-t);
  };
  for (int i = m-1; i >= 0; i--) {
    dp[i][0] = Left(a[i]+1, i+1);
    dp[i][1] = Right(a[i]-1, i+1);
    add(i);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int mi = max(Left(i,0),0);
    int ma = min(Right(i,0),n-1);
    //cout << i << ' ' << mi << ' ' << ma << endl;
    ans += ma-mi+1;
  }
  cout << ans << endl;
}