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
  ll W;
  cin >> n >> W;

  vll a(n);
  for(ll &x : a) cin >> x;

  for(int i = 0; i < n; i++) {
    if(a[i] > W) continue;
    if(2 * a[i] >= W) {
      cout << 1 << '\n' << (i + 1) << '\n';
      return;
    }
  }

  ll sum = 0;
  vint ans;
  for(int i = 0; i < n; i++) {
    if(a[i] > W) continue;
    sum += a[i];
    ans.push_back(i + 1);
    if(2 * sum >= W) {
      cout << ans.size() << '\n';
      for(int &x : ans) cout << x << ' ';
      cout << '\n';
      return;
    }
  }

  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) {
    solve();
  }

  return 0;
}