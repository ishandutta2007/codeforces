#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    string b = s;
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++) ans += s[i] != b[i];
    cout << ans << endl;
  }
}