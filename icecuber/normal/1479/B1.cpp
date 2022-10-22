#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int&v : x) cin >> v;
  int a = -1, b = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int v = x[i];
    if (v == a || (b != v && i+1 < n && x[i+1] == b)) {
      if (v == b) continue;
      else b = v, ans++;
    } else {
      a = v, ans++;
    }
  }
  cout << ans << endl;
}