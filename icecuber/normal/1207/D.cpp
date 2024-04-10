#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3e5+10;
ll fac[nax];
ll mod = 998244353;

#define x first
#define y second
pair<int,int> p[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  fac[0] = 1;
  for (int i = 1; i < nax; i++) {
    fac[i] = fac[i-1]*i%mod;
  }

  int n;
  cin >> n;
  map<int,int> cx, cy;
  map<pair<int,int>,int> cxy;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    cx[p[i].x]++;
    cy[p[i].y]++;
    cxy[p[i]]++;
  }
  ll first = 1, second = 1, both = 1;
  for (auto p : cx)
    (first *= fac[p.second]) %= mod;
  for (auto p : cy)
    (second *= fac[p.second]) %= mod;
  sort(p, p+n);
  for (int i = 1; i < n; i++)
    if (p[i-1].y > p[i].y)
      both = 0;
  for (auto p : cxy)
    (both *= fac[p.second]) %= mod;
  //cout << first << ' ' << second << ' ' << both << endl;
  cout << ((fac[n]-first-second+both)%mod+mod)%mod << endl;
}