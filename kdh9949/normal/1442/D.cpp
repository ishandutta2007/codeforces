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

  int n, k;
  cin >> n >> k;

  vector<vll> a(n + 1);
  vll S(n + 1);
  for(int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    for(int j = 0; j < t; j++) {
      ll x;
      cin >> x;
      if(j < k) {
        a[i].push_back(x);
        S[i] += x;
      }
    }
  }

  vll d(k + 1);
  function<ll(int, int)> f = [&](int s, int e) {
    if(s == e) {
      ll r = d[k], t = 0;
      for(int i = 0; i < a[s].size(); i++) {
        t += a[s][i];
        r = max(r, d[k - 1 - i] + t);
      }
      return r;
    }
    int m = (s + e) / 2;
    vll id = d;
    for(int i = m + 1; i <= e; i++) {
      int t = a[i].size();
      for(int j = k; j >= t; j--) {
        d[j] = max(d[j], d[j - t] + S[i]);
      }
    }
    ll r = f(s, m);
    d = id;
    for(int i = s; i <= m; i++) {
      int t = a[i].size();
      for(int j = k; j >= t; j--) {
        d[j] = max(d[j], d[j - t] + S[i]);
      }
    }
    r = max(r, f(m + 1, e));
    return r;
  };

  cout << f(1, n) << '\n';
  return 0;
}