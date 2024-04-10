#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
ll bin_pow(ll a, ll p) {
  ll r = 1 ;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

ll inv(ll a) {return bin_pow(a, mod-2);}

const int nax = 1<<18;
ll prod[nax];

ll sum[nax*2], off[nax*2];
void mul(int r, ll v) {
  for (int i = r+nax; i > 1; i >>= 1) {
    if (i&1) {
      (off[i-1] *= v) %= mod;
    }
    sum[i>>1] = (sum[i]*off[i]+sum[i^1]*off[i^1])%mod;
  }
}
void mul(int l, int r, ll v) {
  mul(l, inv(v));
  mul(r, v);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  prod[0] = 1;
  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    prod[i+1] = prod[i] * (inv(p)*100%mod) % mod;
  }
  for (int i = 0; i < n; i++)
    sum[nax+i] = 1;
  for (int i = nax-1; i; i--)
    sum[i] = (sum[i*2]+sum[i*2+1])%mod;
  fill_n(off, nax*2, 1);

  for (int i = 0; i < n; i++) {
    mul(i, i+1, prod[n]*inv(prod[i])%mod);
  }

  vector<int> check(n);
  set<int> check_list = {0,n};
  check[0] = 1;
  while (q--) {
    int i;
    cin >> i;
    i--;
    if (check[i]) {
      check[i] = 0;
      check_list.erase(i);
      auto it = check_list.upper_bound(i);
      mul(*prev(it), i, prod[*it]*inv(prod[i])%mod);
    } else {
      auto it = check_list.upper_bound(i);
      mul(*prev(it), i, inv(prod[*it])*prod[i]%mod);
      check[i] = 1;
      check_list.insert(i);
    }
    cout << sum[1] << '\n';
  }
}