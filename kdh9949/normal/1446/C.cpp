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

  int n;
  cin >> n;

  vint a(n);
  for(int &x : a) cin >> x;
  sort(all(a));

  function<int(int, int, int)> f = [&](int s, int e, int b) {
    if(s + 1 >= e) return 0;
    int L = s, R = e;
    int msk = (1 << b);
    while(L < R) {
      int m = (L + R) >> 1;
      if((a[m] & msk) == (a[e] & msk)) R = m;
      else L = m + 1;
    }
    return min(f(s, L - 1, b - 1) + max(0, e - L), f(L, e, b - 1) + max(0, L - 1 - s));
  };

  cout << f(0, n - 1, 30) << '\n';
  return 0;
}