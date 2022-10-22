#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int xl[1000000], yl[1000000];
int main() {
  ios::sync_with_stdio(0);
  ll n, k;
  cin >> n >> k;
  ll a = 0, b = 0;
  for (int i = 0; i < n; i++) cin >> xl[i];
  for (int i = 0; i < n; i++) cin >> yl[i];
  for (int i = 0; i < n; i++) {
    ll x = xl[i], y = yl[i];
    ll na = k+1, nb = k+1;
    if (a <= k) {
      ll b_ = max(1LL,y-k*x);
      if (k*y >= x+a) nb = min(nb, b_);
      ll a_ = max(1LL,x+a-k*y);
      if (k*x >= y) na = min(na, a_);
    }
    if (b <= k) {
      ll a_ = max(1LL,x-k*y);
      if (k*x >= y+b) na = min(na, a_);
      ll b_ = max(1LL,y+b-k*x);
      if (k*y >= x) nb = min(nb, b_);
    }
    //cout << na << ' ' << nb << endl;
    if (na > k && nb > k) {
      cout << "NO" << endl;
      return 0;
    }
    a = na, b = nb;
  }
  cout << "YES" << endl;
}