//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define ull unsigned long long
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

const int MOD = 998244353;

ll pot(ll a, int k) {
  if(k == 0) return 1;
  return a * pot(a, k-1);
}

ll sqr(ll a, int k) {
  ll x = 0, y = 0;
  if(k == 2) y = 1414213563LL;
  if(k == 3) y = 1259922;
  if(k == 4) y = 37607;
  while(y - x > 1) {
    ll m = (x+y)>>1;
    if(pot(m, k) > a) y = m;
    else x = m;
  }
  if(pot(x, k) == a) return x;
  else return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  map <ll, int> roz;
  vector <ll> R;
  vector <ll> X(n, 1);
  #ifdef LOCAL
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    while(x--) {
      ll a;
      cin >> a;
      X[i] *= a;
    }
  }
  #else
  for(int i=0; i<n; i++) cin >> X[i];
  #endif
  for(int _=0; _<n; _++) {
    ll x = X[_];
    for(int i=4; i>=2; i--) {
      ll s = sqr(x, i);
      if(s > 0) {
        roz[s] += i;
        x = 1;
        break;
      }
    }
    if(x != 1) R.push_back(x);
  }
  for(int i=0; i<SZ(R); i++) {
    for(int j=i+1; j<SZ(R); j++) {
      if(R[i] == R[j]) continue;
      ll d = __gcd(R[i], R[j]);
      if(d > 1) {
        roz[d] += 2;
        R[i] /= d;
        R[j] /= d;
        roz[R[i]]++;
        roz[R[j]]++;
        R[i] = 1;
        R[j] = 1;
      }
    }
  }
  for(int i=0; i<SZ(R); i++) {
    for(auto e : roz) {
      if(R[i] % e.x == 0) {
        roz[e.x]++;
        roz[R[i]/e.x]++;
        R[i] = 1;
      }
    }
  }

  sort(ALL(R));
  ll res = 1;
  for(int i=0; i<SZ(R); i++) {
    if(R[i] == 1) continue;
    int ile = 2;
    while(i+1 < SZ(R) and R[i+1] == R[i]) {
      ile++; i++;
    }
    res *= (1LL*ile*ile);
    res %= MOD;
  }
  for(auto e : roz) {
    res *= (e.y + 1);
    res %= MOD;
  }
  cout << res << "\n";
  return 0;
}