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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;

  vll F(6);
  for(ll &x : F) cin >> x;

  const static int N = 1000000;
  const static ll INF = ll(1e18);
  vector<vll> d(6, vll(N, -INF));

  struct DD { deque<int> dq[3]; };

  if(k == 1) { d[5][0] = 0; }
  else {
    for(int i = 0; i <= 3 * (k - 1) && 3 * i < N; i++) d[0][3 * i] = i * F[0];
    for(int i = 1, t = 10; i < 6; i++, t *= 10) {
      if(t >= 10000) {
        for(int j = 0; j < N; j++) {
          for(int x = 0; x <= 3 * (k - 1) && j - 3 * x * t >= 0; x++)
            d[i][j] = max(d[i][j], d[i - 1][j - 3 * x * t] + x * F[i]);
        }
      }
      else {
        vector<DD> v(t);
        for(int j = 0; j < N; j++) {
          int a = j / t, b = j % t;
          DD &cv = v[b];
          d[i][j] = d[i - 1][j];
          deque<int> &dq = cv.dq[a % 3];
          while(!dq.empty() && a - dq.front() > 9 * (k - 1)) dq.pop_front();
          while(!dq.empty() &&
            d[i - 1][dq.back() * t + b] - (dq.back() / 3) * F[i] <=
            d[i - 1][j] - (a / 3) * F[i]) dq.pop_back();
          dq.push_back(a);
          d[i][j] = max(d[i][j], d[i - 1][dq.front() * t + b] + ((a - dq.front()) / 3) * F[i]);
        }
      }
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int x;
    cin >> x;

    ll ans = 0;
    for(int i = 0; i <= x; i++) {
      ll cur = d[5][i];
      int y = x - i;
      for(int j = 0; j < 6; j++) {
        int digit = y % 10;
        if(digit % 3 == 0) cur += (digit / 3) * F[j];
        y /= 10;
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }

  return 0;
}