#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int before[500000], after[500000];
int dp[500000];
int a[500000];
int pos[500001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) before[i] = (i?before[i-1]:0)+(a[i]==c);
  for (int i = n-1; i >= 0; i--) after[i] = (i<n-1?after[i+1]:0)+(a[i]==c);
  fill_n(pos, 500001, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = (i?before[i-1]:0)+1;
    if (pos[a[i]] != -1)
      dp[i] = max(dp[i], dp[pos[a[i]]]+1);
    ans = max(ans, dp[i]+(i<n-1?after[i+1]:0));
    pos[a[i]] = i;
  }
  cout << ans << endl;
}