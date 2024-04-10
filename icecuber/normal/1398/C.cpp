#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int,int> m;
    int acc = 0;
    m[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int d = s[i]-'1';
      acc += d;
      ans += m[acc]++;
    }
    cout << ans << endl;
  }
}