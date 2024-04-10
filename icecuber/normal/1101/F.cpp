#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[400];
int ok(ll s, ll f, ll c, ll r, ll v) {
  int di = f > s ? 1 : -1;
  ll fuel = v;
  int refuels = 0;
  for (int i = s; i != f; i += di) {
    ll dist = abs(a[i+di]-a[i])*c;
    if (dist > fuel) fuel = v, refuels++;
    if (dist > fuel) return 0;
    fuel -= dist;
  }
  return refuels <= r;
}

struct Truck {
  ll s, f, c, r;
};
Truck truck[250000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> truck[i].s >> truck[i].f >> truck[i].c >> truck[i].r;
    truck[i].s--, truck[i].f--;
  }
  for (int i = 0; i < m; i++)
    swap(truck[i], truck[uniform_int_distribution<int>(0,i)(rng)]);
  ll v = 0;
  for (int i = 0; i < m; i++) {
    if (ok(truck[i].s, truck[i].f, truck[i].c, truck[i].r, v)) continue;
    ll fail = v, pass = 1e18;
    while (fail+1 < pass) {
      ll mid = fail+pass>>1;
      if (ok(truck[i].s, truck[i].f, truck[i].c, truck[i].r, mid)) pass = mid;
      else fail = mid;
    }
    v = pass;
  }
  cout << v << endl;
}