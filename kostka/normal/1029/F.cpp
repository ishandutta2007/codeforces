//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  ll a, b;
  cin >> a >> b;
  ll s = a + b;
  vector <ll> D;
  for(ll i=1; i*i <= s; i++) {
    if(s % i == 0) {
      D.push_back(s / i);
      D.push_back(i);
    }
  }
  sort(ALL(D));
  ll res = 1LL<<60;
  vector <ll> X = {a, b};
  for(auto x : X) {
    vector <ll> E;
    for(ll i=1; i*i <= x; i++) {
      if(x % i == 0) {
        E.push_back(x / i);
        E.push_back(i);
      }
    }
    sort(ALL(E));
    for(auto d : D) {
      auto e = *prev(upper_bound(ALL(E), d));
      if(x/e <= s/d) res = min(res, d + s/d);
    }
  }
  cout << 2 * res << "\n";
  return 0;
}