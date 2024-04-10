#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt[256] = {};
    for (char c : s) cnt[c]++;
    char ma = max_element(cnt, cnt+256)-cnt;
    char ans = 'R';
    if (ma == 'R') ans = 'P';
    else if (ma == 'P') ans = 'S';
    for (int i = 0; i < n; i++)
      cout << ans;
    cout << endl;
  }
}