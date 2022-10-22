#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define D(x) #x << " = " << x

int prime[301], primes = 0;
ll a_mask[301], tot[301];

ll mod = 1e9+7;

ll mypow(ll a, ll p = mod-2) {
  ll r = 1;
  while (p) {
    if (p%2) r = r*a%mod;
    a = a*a%mod;
    p /= 2;
  }
  return r;
}

const int nax = 1<<19;
ll prod[nax*2], prod_lazy[nax*2], mask[nax*2], mask_lazy[nax*2];
void prop(int i, int w) {
  if (prod_lazy[i] != 1 || mask_lazy[i]) {
    (prod[i] *= mypow(prod_lazy[i], w)) %= mod;
    mask[i] |= mask_lazy[i];
    if (i < nax) {
      (prod_lazy[i*2] *= prod_lazy[i]) %= mod;
      (prod_lazy[i*2+1] *= prod_lazy[i]) %= mod;
      mask_lazy[i*2] |= mask_lazy[i];
      mask_lazy[i*2+1] |= mask_lazy[i];
    }
    prod_lazy[i] = 1;
    mask_lazy[i] = 0;
  }
}

void mul(int a, int b, ll v, ll m, int l = 0, int r = nax, int i = 1) {
  if (a <= l && b >= r) {
    (prod_lazy[i] *= v) %= mod;
    mask_lazy[i] |= m;
  } else if (a < r && b > l) {
    int mid = l+r>>1;
    mul(a, b, v, m, l, mid, i*2);
    mul(a, b, v, m, mid, r, i*2+1);
    prod[i] = prod[i*2] * prod[i*2+1] % mod;
    mask[i] = mask[i*2] | mask[i*2+1];
  }
  prop(i, r-l);
}

pair<ll,ll> query(int a, int b, int l = 0, int r = nax, int i = 1) {
  prop(i, r-l);
  if (a <= l && b >= r) {
    return {prod[i], mask[i]};
  } else if (a < r && b > l) {
    int mid = l+r>>1;
    auto p = query(a, b, l, mid, i*2);
    auto q = query(a, b, mid, r, i*2+1);
    return {p.first*q.first%mod, p.second|q.second};
  } else return {1,0};
}

int main() {
  fill_n(prod, nax*2, 1);
  fill_n(prod_lazy, nax*2, 1);

  for (int i = 2; i < 301; i++) {
    int isprime = 1;
    for (int j = 2; j < i; j++)
      if (i%j == 0) isprime = 0;
    if (isprime)
      prime[primes++] = i;
    for (int j = 0; j < primes; j++)
      if (i%prime[j] == 0) a_mask[i] |= 1ll<<j;
  }
  for (int i = 0; i < primes; i++)
    tot[i] = 1+mod-mypow(prime[i]);
  assert(primes<64);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mul(i, i+1, a, a_mask[a]);
  }
  while (q--) {
    string cmd;
    cin >> cmd;
    int l, r;
    cin >> l >> r;
    l--;
    if (cmd == "MULTIPLY") {
      int a;
      cin >> a;
      mul(l, r, a, a_mask[a]);
    } else {
      auto p = query(l, r);
      ll ans = p.first;
      for (int i = 0; i < primes; i++)
	if (p.second>>i&1)
	  (ans *= tot[i]) %= mod;
      cout << (ans+mod)%mod << endl;
    }
  }
}