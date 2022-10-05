#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    if(n == 1) { cout << "0\n"; continue; }

    int ans = a[n - 1] - a[0];
    ans = max(ans, *max_element(a.begin() + 1, a.end()) - a[0]);
    ans = max(ans, a[n - 1] - *min_element(a.begin(), a.end() - 1));
    for(int i = 0; i + 1 < n; ++i) ans = max(ans, a[i] - a[i + 1]);

    cout << ans << '\n';
  }

  return 0;
}