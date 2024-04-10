#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  int a[300] = {};
  int m = 0;
  for (int v : s)
    a[m++] = v;
  int ans;
  if (m > 3 || m == 3 && a[2]-a[1] != a[1]-a[0]) {
    ans = -1;
  } else if (m == 1) ans = 0;
  else if (m == 3)
    ans = a[2]-a[1];
  else if (m == 2) {
    ans = a[1]-a[0];
    if (ans%2==0) ans /= 2;
  }
  cout << ans << endl;
}