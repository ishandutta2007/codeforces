#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int w, h;
    cin >> w >> h;
    if (w == 1 && h == 1) cout << 0 << endl;
    else if (w == 1 || h == 1) cout << 1 << endl;
    else cout << 2 << endl;
  }
}