#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];
ll dp[100001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll sum = 0;
  multiset<int> s;
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    s.insert(a[i]);
    if (i >= c) s.erase(s.find(a[i-c]));
    dp[i+1] = dp[i];
    if (i >= c-1) {
      dp[i+1] = max(dp[i+1], dp[i+1-c]+*s.begin());
    }
  }
  cout << sum-dp[n] << endl;
}