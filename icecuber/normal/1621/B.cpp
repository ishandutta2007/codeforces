#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int mi = 1e9+10, ma = -1e9;
    map<array<int,2>,int> has;
    map<int,int> A, B;
    for (int i = 0; i < n; i++) {
      int l, r, c;
      cin >> l >> r >> c;
      mi = min(mi, l);
      ma = max(ma, r);
      array<int,2> p = {l,r};
      if (has.count(p)) has[p] = min(has[p], c);
      else has[p] = c;

      if (A.count(l)) A[l] = min(A[l], c);
      else A[l] = c;
      if (B.count(r)) B[r] = min(B[r], c);
      else B[r] = c;

      int ans = A[mi]+B[ma];
      if (has.count({mi,ma})) ans = min(ans, has[{mi,ma}]);
      cout << ans << endl;
    }
  }
}