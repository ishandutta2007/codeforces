#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ok[26];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  while (k--) {
    char c;
    cin >> c;
    ok[c-'a'] = 1;
  }
  ll ans = 0, streak = 0;
  for (char c : s) {
    if (ok[c-'a']) {
      ans += ++streak;
    } else streak = 0;
  }
  cout << ans << endl;
}