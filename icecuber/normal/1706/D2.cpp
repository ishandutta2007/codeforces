#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+10;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<array<int,2>>> a(nax);
    int mi = nax;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      a[v].push_back({v,1});
      mi = min(mi, v);
    }
    int ans = nax;
    for (int ma = nax-1; ; ma--) {
      ans = min(ans, ma-mi);
      if (ma == 0) break;
      for (auto [v,d] : a[ma]) {
        int nv = min(v/(d+1), v/d-1);
        int nd = v/(nv+1)+1;
        assert(nv == v/nd);
        if (nd > k) goto done;
        a[nv].push_back({v,nd});
        mi = min(mi, nv);
      }
      a[ma].clear();
      a[ma].shrink_to_fit();
    }
done:
    cout << ans << endl;
  }
}