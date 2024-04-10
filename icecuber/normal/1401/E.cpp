#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 1e6;
const int nax = m+10;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb;
  cin >> na >> nb;
  vector<vector<array<int,2>>> hori(m+1);
  for (int i = 0; i < na; i++) {
    int y, lx, rx;
    cin >> y >> lx >> rx;
    hori[y].push_back({lx,rx});
  }
  vector<vector<array<int,2>>> vert(m+1);
  for (int i = 0; i < nb; i++) {
    int x, ly, ry;
    cin >> x >> ly >> ry;
    vert[ly].push_back({x,ry});
  }

  vector<ll> data(nax);
  auto add = [&](int i, int v) {
    for (i += 5; i < nax; i += i&-i)
      data[i] += v;
  };
  auto sum1 = [&](int i) {
    ll r = 0;
    for (i += 5; i; i -= i&-i)
      r += data[i];
    return r;
  };
  auto sum = [&](int l, int r) {
    return sum1(r)-sum1(l-1);
  };
  ll ans = 1;
  vector<vector<int>> rem(m+1);
  add(0,1);
  add(m,1);
  for (int i = 0; i <= m; i++) {
    for (auto [x,ry] : vert[i]) {
      add(x,1);
      if (i == 0 && ry == m) ans++;
      rem[ry].push_back(x);
    }
    for (auto [lx,rx] : hori[i]) {
      ans += sum(lx,rx)-1;
    }
    for (int x : rem[i]) {
      add(x,-1);
    }
  }
  cout << ans << endl;
}