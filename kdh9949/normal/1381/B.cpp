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

  int mx = 0, cnt;
  vint v;
  for(int i = 0; i < 2 * n; i++) {
    int x;
    cin >> x;
    if(mx < x) {
      if(mx) v.push_back(cnt);
      mx = x;
      cnt = 1;
    }
    else cnt++;
  }
  v.push_back(cnt);

  vint d(n + 1, 0);
  d[0] = 1;
  for(int x : v) {
    for(int i = n; i >= x; i--) d[i] |= d[i - x];
  }
  cout << (d[n] ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) solve();

  return 0;
}