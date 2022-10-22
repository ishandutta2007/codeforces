#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    cout << min(abs(a-b)+x, n-1) << endl;
  }
}