#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

void solve() {
  int n;
  cin >> n;

  int cnt[30][2] = {};
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for(int j = 0; j < 30; j++) {
      cnt[j][(x >> j) & 1]++;
    }
  }

  for(int i = 29; i >= 0; i--) {
    if(cnt[i][1] & 1) {
      int one = cnt[i][1] % 4;
      int zero = cnt[i][0] % 2;
      if(one == 3 && zero == 0) cout << "LOSE\n";
      else cout << "WIN\n";
      return;
    }
  }

  cout << "DRAW\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) solve();

  return 0;
}