#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    int m = 1;
    while (k > m*2-1) {
      k -= m*2-1;
      m++;
    }
    if (k <= m) cout << k << ' ' << m << endl;
    else cout << m << ' ' << m*2-k << endl;
  }
}