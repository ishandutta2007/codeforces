#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x;
  cin >> x;
  string s = "DACB";
  char ans = 'E';
  int best = -1;
  for (int i = 0; i < 3; i++) {
    char c = s[x+i&3];
    if (c < ans) {
      ans = c;
      best = i;
    }
  }
  cout << best << ' ' << ans << endl;
}