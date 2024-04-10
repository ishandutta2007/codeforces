#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int mi = n, ma = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '*' || b[i] == '*') {
        mi = min(mi, i);
        ma = max(ma, i);
      }
    }
    int ca = 0, cb = 0;
    for (int i = mi; i <= ma; i++) {
      if (a[i] == '.' && b[i] == '.') {
        ca++;
        cb++;
      } else if (a[i] == '*' && b[i] == '*') {
        int c = min(ca+2,cb+2);
        ca = cb = c;
      } else if (a[i] == '*' && b[i] == '.') {
        tie(ca,cb) = make_pair(min(ca+1,cb+2), min(ca+2,cb+2));
      } else if (a[i] == '.' && b[i] == '*') {
        tie(ca,cb) = make_pair(min(ca+2,cb+2), min(ca+2,cb+1));
      } else assert(0);
    }
    cout << min(ca,cb)-1 << endl;
  }
}