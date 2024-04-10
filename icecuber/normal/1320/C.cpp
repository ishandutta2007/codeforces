#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> read(int n) {
  vector<pair<int,int>> r(n);
  for (auto&[a, ca] : r)
    cin >> a >> ca;
  sort(r.begin(), r.end());
  vector<pair<int,int>> r2;
  for (auto [a,ca] : r) {
    if (r2.empty() || r2.back().first != a)
      r2.emplace_back(a,ca);
  }
  return r2;
}

const int n = 1<<20;
ll ma[n*2], off[n*2];
void add(int r, ll v) {
  for (int i = n+r; i; i >>= 1) {
    if (i&1) {
      off[i-1] += v;
    }
    ma[i>>1] = max(ma[i]+off[i], ma[i^1]+off[i^1]);
  }
}

const int nax = 1e6+10;
vector<pair<int,int>> monst[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb, m;
  cin >> na >> nb >> m;
  auto a = read(na);
  auto b = read(nb);

  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    monst[x].emplace_back(y,z);
  }

  int last = -1;
  for (auto [x,c] : b) {
    add(last+1, c);
    add(x+1, -c);
    last = x;
  }
  add(last+1, 2e12);
  off[1] -= 2e12;

  ll ans = -2e12;
  int j = 0;
  for (int x = 0; x < nax; x++) {
    while (j < a.size() && a[j].first < x) j++;
    if (j == a.size()) break;
    ll score = ma[1]+off[1]-a[j].second;
    ans = max(ans, score);

    for (auto [y,z] : monst[x]) {
      add(y+1, -z);
      add(last+1, z);
    }
  }
  cout << ans << endl;
}