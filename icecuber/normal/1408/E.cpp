#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<array<int,2>> node[nax];

int par[nax];
int Find(int p) {
  return p == par[p] ? p : par[p] = Find(par[p]);
}

int main() {
  for (int i = 0; i < nax; i++)
    par[i] = i;
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb;
  cin >> na >> nb;
  vector<ll> ca(na), cb(nb);
  for (ll&v : ca) cin >> v;
  for (ll&v : cb) cin >> v;

  vector<array<int,3>> edge;
  for (int i = 0; i < na; i++) {
    int k;
    cin >> k;
    while (k--) {
      int j;
      cin >> j;
      j--;
      edge.push_back({ca[i]+cb[j],i,na+j});
    }
  }
  sort(edge.rbegin(), edge.rend());
  ll ans = 0;
  for (auto [cost,a,b] : edge) {
    a = Find(a);
    b = Find(b);
    if (a == b) ans += cost;
    else par[a] = b;
  }
  cout << ans << endl;
}