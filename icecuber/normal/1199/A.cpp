#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  for (int i = 0; i < n; i++) {
    int ok = 1;
    for (int j = max(i-x,0); j <= min(i+y,n-1); j++)
      if (a[j] < a[i]) ok = 0;
    if (ok) {
      cout << i+1 << endl;
      return 0;
    }
  }
}