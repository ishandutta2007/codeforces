#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), last(n+1);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    last[a[i]] = i;
  }
  int ans = n;
  int reach = -1, cur = -1;
  for (int i = 0; i < n; i++) {
    if (i > reach) cur = reach = i, ans--;
    if (i > cur) cur = reach, ans--;
    reach = max(reach, last[a[i]]);
  }
  cout << ans << endl;
}