#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int w) {
  cout << "? " << w << endl;
  int h;
  cin >> h;
  return h;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int pass = n*2000+n-1, fail = 0;
  while (pass-fail > 1) {
    int mid = (pass+fail)/2;
    if (query(mid) == 1) pass = mid;
    else fail = mid;
  }
  int ans = pass;
  for (int h = 2; h <= n; h++) {
    int w = (pass+1 +h-1)/h-1;
    int q = query(w);
    if (q)
      ans = min(ans, q*w);
  }
  cout << "! " << ans << endl;
}