#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    set<int> ans = {0};
    for (int i = 1; i*i <= n; i++) {
      ans.insert(i);
      ans.insert(n/i);
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
  }
}