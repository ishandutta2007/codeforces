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
    int oka = 1, okb = 1;
    for (char c : s) {
      if (c == '>') oka = 0;
      if (c == '<') okb = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '-' || s[(i+1)%n] == '-') ans++;
    }
    if (oka || okb) ans = n;
    cout << ans << endl;
  }
}