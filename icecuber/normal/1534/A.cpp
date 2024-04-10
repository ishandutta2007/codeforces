#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<string> inp(h), a(h), b(h);
    int oka = 1, okb = 1;
    for (int i = 0; i < h; i++) {
      string s;
      cin >> inp[i];
      for (int j = 0; j < w; j++) { 
        if (i+j&1) a[i] += 'R', b[i] += 'W';
        else a[i] += 'W', b[i] += 'R';
        if (inp[i][j] != '.') {
          if (inp[i][j] != a[i][j]) oka = 0;
          if (inp[i][j] != b[i][j]) okb = 0;
        }
      }
    }
    if (oka) {
      cout << "YES" << endl;
      for (string s : a) cout << s << endl;
    } else if (okb) {
      cout << "YES" << endl;
      for (string s : b) cout << s << endl;
    } else
      cout << "NO" << endl;
  }
}