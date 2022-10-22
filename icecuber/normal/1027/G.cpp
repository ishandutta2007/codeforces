#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void factor(ll m, vector<ll>&factors, vector<ll>&divisors) {
  ll r = m;
  divisors.push_back(m);
  for (ll i = 2; i*i <= m; i++) {
    if (m%i) continue;
    divisors.push_back(i);
    if (i*i != m) {
      divisors.push_back(m/i);
    }
    if (r%i == 0) {
      factors.push_back(i);
      while (r%i == 0) {
	r /= i;
      }
    }
  }
  if (r > 1) factors.push_back(r);
}

ll mul(ll a, ll p, ll m) {
  ll r = 0;
  while (p) {
    if (p&1) {
      r = r+a;
      if (r >= m) r -= m;
    }
    a = a+a;
    if (a >= m) a -= m;
    p >>= 1;
  }
  return r;
}

ll bin_pow(ll a, ll p, ll m) {
  ll r = 1;
  while (p) {
    if (p&1) {
      r = mul(r,a,m);
    }
    a = mul(a,a,m);
    p >>= 1;
  }
  return r;
}

ll solve(vector<ll>&factors, vector<ll>&phi_factors, ll d, ll x) {
  x %= d;
  ll phi = 1, r = d;
  for (ll f : factors) {
    if (r%f) continue;
    r /= f;
    phi *= f-1;
    while (r%f == 0) {
      r /= f;
      phi *= f;
    }
  }
  assert(r == 1);
  //cout << x << ' ' << phi << ' ' << d << ' ' << bin_pow(x, phi, d) << endl;
  assert(bin_pow(x, phi, d) == 1);
  ll order = phi;
  for (ll f : phi_factors) {
    while (order%f == 0 && bin_pow(x, order/f, d) == 1) {
      order /= f;
    }
  }
  return phi/order;
}

vector<ll> m1factors(vector<ll>&factors) {
  vector<ll> phi_factors = factors;
  for (ll f : factors) {
    f--;
    for (ll i = 2; i*i <= f; i++) {
      if (f%i == 0) {
	phi_factors.push_back(i);
	while (f%i == 0) f /= i;
      }
    }
    if (f > 1) phi_factors.push_back(f);
  }
  phi_factors.resize(unique(phi_factors.begin(), phi_factors.end())-phi_factors.begin());
  return phi_factors;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll m, x;
  cin >> m >> x;
  vector<ll> factors, divisors;
  factor(m, factors, divisors);

  vector<ll> phi_factors = m1factors(factors);
  ll ans = 1; //Zero
  for (ll d : divisors) {
    //cout << d << ' ' << solve(factors, phi_factors, d, x) << endl;
    ans += solve(factors, phi_factors, d, x);
  }
  cout << ans << endl;
}