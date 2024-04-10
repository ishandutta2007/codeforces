#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0, acc = 0;
  for (char c : s) {
    int bad = acc < 0;
    acc += (c == '(')*2-1;
    ans += bad || acc<0;
  }
  if (acc != 0) {
    cout << -1 << endl;
  } else
    cout << ans << endl;
}