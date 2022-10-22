#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  vector<vector<int>> cnt(nax, vector<int>(20));
  for (int i = 0; i < nax-1; i++) {
    for (int b = 0; b < 20; b++) {
      cnt[i+1][b] = cnt[i][b]+(i>>b&1);
    }
  }
  while (T--) {
    int l, r;
    cin >> l >> r;
    r++;
    int ans = r-l;
    for (int b = 0; b < 20; b++) {
      int ones = cnt[r][b]-cnt[l][b]; 
      int zeros = r-l-ones;
      if (ones) ans = min(ans, zeros);
    }
    cout << ans << endl;
  }
}