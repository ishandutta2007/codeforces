#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  return b ? gcd(b, a%b) : a;
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  if (n*m*2%k) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    if (gcd(n*2, k) >= 2) {
      int g = gcd(n*2, k);
      cout << 0 << ' ' << 0 << endl;
      cout << n*2/g << ' ' << 0 << endl;
      cout << 0 << ' ' << m*g/k << endl;
    } else {
      int g = gcd(m*2, k);
      cout << 0 << ' ' << 0 << endl;
      cout << n*g/k << ' ' << 0 << endl;
      cout << 0 << ' ' << m*2/g << endl;
    }
  }
}