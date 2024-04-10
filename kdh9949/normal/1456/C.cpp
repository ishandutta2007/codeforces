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
#define all(v) (v).begin(),(v).end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vll a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  sort(all(a), greater<ll>());
  ll ans = 0, cur = 0;
  vll b;
  for(int i = 0; i < n; i++) {
    ans += cur;
    cur += a[i];
    if(cur < 0) {
      if(i < n - 1) b.push_back(-cur);
      for(int j = i + 1; j < n - 1; j++) b.push_back(-a[j]);
      break;
    }
  }
  
  if(b.size()) {
    int m = b.size();
    k = min(m, k);

    ll penalty = 0;
    if(k >= m - k - 1) {
      for(int i = 0; i < m - k; i++) penalty += b[i];
    }
    else {
      int sz = (m - k) / (k + 1);
      int bnum = (m - k) % (k + 1);
      int snum = k + 1 - bnum;
      vint c(m - k);
      for(int i = 0; i < bnum; i++) c[i] = sz + 1;
      for(int i = bnum, t = (sz + 1) * (k + 1) - 1; i < m - k; i++, t--) {
        c[i] = t / (k + 1);
      }
      for(int i = 0; i < m - k; i++) penalty += b[i] * c[i];
    }

    ans -= penalty;
  }

  cout << ans << '\n';
  return 0;
}