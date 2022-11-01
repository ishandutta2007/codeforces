//============================================================================
// Name        : F.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

vector<int> prevPrime(1000001, 0);

int mu(int p) {
  int res = 1;
  while (p != 1) {
    int x = prevPrime[p];
    int c = 0;
    while (p % x == 0) {
      ++c;
      p /= x;
    }
    if (c > 1)
      return 0;
    res = -res;
  }
  return res;
}

typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll x, ll po) {
  ll res = 1;
  while (po != 0) {
    if (po % 2 == 1) {
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    po /= 2;
  }
  return res;
}

ll inv(ll x) {
  return modpow(x, MOD - 2);
}

vector<ll> fact(1, 1), invfact(1, 1);

ll comb(ll n, ll k) {
  if (k > n)
    return 0;
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

vector<ll> divisors(int k) {
  if (k == 1) return {1};
  int p = prevPrime[k];
  int c = 0;
  while (k % p == 0) {
    ++c;
    k /= p;
  }
  vector<ll> res = divisors(k);
  int len = (int)res.size();
  for (int i = 0; i < len; ++i) {
    int y = res[i];
    for (int j = 0; j < c; ++j) {
      y *= p;
      res.push_back(y);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
	for (int i = 2; i <= 1000000; ++i) {
	  if (prevPrime[i] == 0) {
	    prevPrime[i] = i;
	    for (int j = i * 2; j <= 1000000; j += i) {
	      if (prevPrime[j] == 0)
	        prevPrime[j] = i;
	    }
	  }
	}
	vector<long long> coeff(1000001);
	for (int i = 1; i <= 1000000; ++i) {
	  fact.push_back(fact[i-1] * i % MOD);
	  invfact.push_back(inv(fact[i]));
	  int m = mu(i);
	  if (m == 0)
	    continue;
	  for (int j = i; j <= 1000000; j += i) {
	    coeff[j] += m * (j / i);
	    coeff[j] %= MOD;
	  }
	}
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> counts(1000001);
	ll res = 0;
	auto add_val = [&](ll v) {
	  for (int d: divisors(v)) {
	    //res -= coeff[d] * comb(counts[d], k);
	    res += coeff[d] * comb(counts[d], k - 1);
	    counts[d] += 1;
	    res %= MOD;
	    if (res < 0)
	      res += MOD;
	  }
	};
	for (int i = 0; i < n; ++i) {
	  int t;
	  cin >> t;
	  add_val(t);
	}
	for (int i = 0; i < q; ++i) {
	  int t;
	  cin >> t;
	  add_val(t);
	  cout << res << endl;
	}

	return 0;
}