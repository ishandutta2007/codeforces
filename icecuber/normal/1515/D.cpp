#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<array<int,2>> cnt(n);
    int cols[2] = {}, tot[2] = {};
    int have = 0;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      c--;
      int s = (i < l);
      if (cnt[c][!s]) {
        if (!--cnt[c][!s]) cols[!s]--;
        tot[!s]--;
        have++;
      } else {
        if (!cnt[c][s]++) cols[s]++;
        tot[s]++;
      }
    }
    int free[2] = {};
    for (int i = 0; i < n; i++) {
      for (int s : {0,1}) {
        free[s] += cnt[i][s]/2;
      }
    }
    int ans = 0;
    int mv = 0;
    if (tot[0] < tot[1]) {
      mv = min(free[1], (tot[1]-tot[0])/2);
      ans += mv;
      tot[1] -= mv*2;
    } else if (tot[1] < tot[0]) {
      mv = min(free[0], (tot[0]-tot[1])/2);
      ans += mv;
      tot[0] -= mv*2;
    }
    mv = (tot[1]-tot[0])/2;
    ans += abs(mv);
    tot[0] += mv;
    tot[1] -= mv;
    assert(tot[0] == tot[1]);
    ans += tot[0];
    cout << ans << endl;
  }
}