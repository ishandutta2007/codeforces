#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int last = 0, streak = 0, laststreak = 0, ans = 0;
  for (int i = 0; i <= n; i++) {
    int t = -1;
    if (i < n)
      cin >> t;
    if (t == last) streak++;
    else {
      ans = max(ans, min(laststreak, streak)*2);
      laststreak = streak;
      streak = 1;
      last = t;
    }
  }
  cout << ans << endl;
}