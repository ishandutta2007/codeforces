#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  int ans = 0;
  for (int j = -1; j <= n; j++) {
    int score = 0;
    for (int k = 0; k < n; k++) {
      score += (a[k] == (k > j));
    }
    ans = max(ans, score);
  }
  cout << ans << endl;
}