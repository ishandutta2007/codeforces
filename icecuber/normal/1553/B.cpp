#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string a, b;
    cin >> a >> b;
    int ok = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      for (int j = i; j < (int)a.size(); j++) {
        for (int k = j; k >= 0; k--) {
          if (j-i+j-k+1 == (int)b.size()) {
            string c = a.substr(i,j-i+1);
            string r = a.substr(k,j-k);
            reverse(r.begin(), r.end());
            if (c+r == b) ok = 1;
          }
        }
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}