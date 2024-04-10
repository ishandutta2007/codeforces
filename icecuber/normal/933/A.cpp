#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> acc = {0};
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    acc.push_back(acc.back()+(a==2));
  }
  int ans = 0;
  for (int m = 0; m < n; m++) {
    int l = 0;
    for (int i = 0; i <= m; i++) {
      l = max(l, i-acc[i] + acc[m]-acc[i]);
    }
    int r = 0;
    for (int i = m; i <= n; i++) {
      r = max(r, i-m - (acc[i]-acc[m]) + acc[n]-acc[i]);
    }
    ans = max(ans, l+r);
  }
  cout << ans << endl;
}