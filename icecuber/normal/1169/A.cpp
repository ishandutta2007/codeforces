#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  int ok = 0;
  while (1) {
    if (a == b) ok = 1;
    if (a == x || b == y) break;
    a = (a+1-1)%n+1;
    b = (b+n-1-1)%n+1;
  }
  cout << (ok ? "YES" : "NO") << endl;
}