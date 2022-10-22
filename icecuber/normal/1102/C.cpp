#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  int breakable = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    breakable += a<=x;
  }
  if (x > y) cout << n << endl;
  else cout << (breakable+1)/2 << endl;
}