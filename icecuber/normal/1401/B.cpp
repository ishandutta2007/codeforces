#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a0, a1, a2, b0, b1, b2;
    cin >> a0 >> a1 >> a2;
    cin >> b0 >> b1 >> b2;
    int good = min(a2,b1);
    cout << 2*(good-max(b2+good-a2-a0,0)) << endl;
  }
}