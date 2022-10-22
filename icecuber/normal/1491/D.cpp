#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    int ok = (a <= b);

    int acc = 0, alast = 0;
    for (int i = 0; i < 30; i++) {
      int ai = a>>i&1;
      int bi = b>>i&1;
      if (ai && bi) {
        continue;
      } else if (ai && !bi) {
        acc++;
        alast = 1;
      } else if (bi && !ai) {
        if (--acc < 0) ok = 0;
        alast = 0;
      } else if (!ai && !bi) {
        continue;
      }
    }
    if (alast) ok = 0;
    ok |= (a == b);
    cout << (ok ? "YES" : "NO") << endl;
  }
}