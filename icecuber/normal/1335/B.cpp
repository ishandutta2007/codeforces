#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    string ans;
    for (int i = 0; i < n; i++) {
      ans += 'a'+min(i%a,b-1);
    }
    cout << ans << endl;
  }
}