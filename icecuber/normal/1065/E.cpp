#include <iostream>

using namespace std;

typedef long long ll;

ll mod = 998244353;

ll pow(ll a, ll p) {
  ll r = 1, b = a;
  while (p) {
    if (p&1) r = (r*b)%mod;
    b = (b*b)%mod;
    p >>= 1;
  }
  return r;
}
int main() {
  ll n, m, A;
  cin >> n >> m >> A;

  ll r = 1;
  ll last = 0;
  for (int i = 0; i < m; i++) {
    ll b;
    cin >> b;
    ll a = (b-last);
    (r *= pow(A, 2*a)+pow(A, a)) %= mod;
    r = ((mod+1)/2*r)%mod;
    last = b;
  }
  (r *= pow(A, n-2*last)) %= mod;
  cout << (r%mod+mod)%mod << endl;
}