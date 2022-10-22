#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll mod_mul_slow(ll a, ll p, ll m) {
  a %= m;
  p %= m;
  ll r = 0;
  while (p) {
    if (p&1) {
      r += a;
      if (r >= m) r -= m;
    }
    a += a;
    if (a >= m) a -= m;
    p >>= 1;
  }
  return r;
}

ll mod_mul(ull a, ull b, ull m) {
  //a %= m;
  //b %= m;
  ll r = a*b-ull((ld)a*b/m)*m;
  while (r < 0) r += m;
  return r%m;
}

ll mod_pow(ll a, ll p, ll m) {
  ll r = 1;
  while (p) {
    if (p&1) r = mod_mul(r,a,m);
    a = mod_mul(a,a,m);
    p >>= 1;
  }
  return r;
}

bool isPrime(ll n) {
  if (n <= 1) return 0;
  if (n%6%4 != 1) return n == 2 || n == 3;
  ll A[] = {2,3,5,7,11,13,17,19,23,29,31,37};
  for (ll a : A) {
    a %= n;
    if (a < 2 || a > n-2) continue;
    ll d = n-1;
    d /= d&-d;
    ll x = mod_pow(a, d, n);
    if (x == 1 || x == n-1) continue;
    while (1) {
      d *= 2;
      if (d >= n-1) return 0;
      x = mod_mul(x,x,n);
      if (x == n-1) break;
    }
  }
  return 1;
}



mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

ll pollard(ll n) {
  if (n%2 == 0) return 2;
  auto f = [&](ll x) {return (mod_mul(x,x,n)+1)%n;};
  ll x, y, d = n;
  while (d == 1 || d == n) {
    if (d == n)
      x = mrand()%(n-1)+1, y = f(x);
    //cout << x << ' ' << y << endl;
    d = __gcd(abs(x-y),n);
    x = f(x);
    y = f(f(y));
  }
  return d;
}

vector<ll> factors(ll n) {
  if (isPrime(n)) return {n};
  ll d = pollard(n);
  vector<ll> r = factors(d);
  for (ll f : factors(n/d)) r.push_back(f);
  return r;
}

int main() {
  /*{
    ll m = 741856993479139999;
    cout << isPrime(m) << endl;
    for (ll d = 2; d*d <= m; d++) {
      if (m%d == 0) cout << d << endl;
    }
    return 0;
    }*/
  //cout << pollard(25) << endl;
  //return 0;
  /*vector<int> isprime(1e6,1);
  for (int i = 2; i < 1e6; i++) {
    if (isprime[i] != isPrime(i)) {
      cout << i << endl;
      cout << isPrime(i) << endl;
      return 0;
    }
    if (!isprime[i]) continue;
    for (int j = i*2; j < 1e6; j += i)
      isprime[j] = 0;
  }
  cout << "OK" << endl;*/
  /*for (ll i : factors(315380239985874944ll))
    cout << i << '*';
  cout << endl;
  return 0;*/

  ll n, m, p;
  cin >> n >> m >> p;

  vector<ll> ans;
  if (__gcd(p,m) > 1 || m < 2e6) {
    set<ll> st;
    ll x = 1;
    while (!st.count(x)) {
      st.insert(x);
      x = mod_mul(x,p,m);
    }

    for (ll i = 2; i < m; i++) {
      if (__gcd(i,m) > 1 || st.count(i)) continue;
      ans.push_back(i);
      if (ans.size() == n) break;
    }
  } else if (m%2 == 0) {
    for (ll i = 3; i < m; i+=2) {
      if (i%8 == 1 || i%8 == p%8) continue;
      ans.push_back(i);
      if (ans.size() == n) break;
    }
  } else {
    ll phi = m-m/factors(m)[0];
    ll order = phi;
    vector<ll> facs = factors(phi);
    for (ll f : facs) {
      while (order%f == 0 && mod_pow(p, order/f, m) == 1)
	order /= f;
    }

    if (phi-order < n) goto fail;

    ll g = 1;
    while (g++) {
      for (ll f : facs)
	if (mod_pow(g, phi/f, m) == 1) goto next;
      break;
    next:;
    }

    ll tabu = phi/order, x = 1;
    for (int i = 0; i < phi; i++) {
      if (i%tabu) {
	ans.push_back(x);
	if (ans.size() == n) break;;
      }
      x = mod_mul(x, g, m);
    }
  }
 fail:
  if (ans.size() == n) {
    for (ll i : ans) cout << i << ' ';
    cout << endl;
  } else cout << -1 << endl;
}