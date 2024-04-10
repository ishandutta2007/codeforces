#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());

  vector<int> done(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    ans++;
    for (int j = 0; j < n; j++) {
      if (a[j]%a[i] == 0) done[j] = 1;
    }
  }
  cout << ans << endl;
}