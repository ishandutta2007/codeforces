#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define data elgkjelrkgj
const int nax = 1<<18;
ll data[nax*2], mi[nax*2];

void add(int a, int b, ll v, int l = 0, int r = nax, int i = 1) {
  if (a <= l && b >= r) {
    data[i] += v;
    mi[i] += v;
    return;
  } else if (a >= r || b <= l) return;
  int m = (l+r)/2;
  add(a, b, v, l, m, i*2);
  add(a, b, v, m, r, i*2+1);
  mi[i] = min(mi[i*2], mi[i*2+1])+data[i];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector<ll> cost(n);
  for (ll&v : cost) cin >> v;

  for (int i = 0; i < n; i++) {
    add(p[i]+1, nax, cost[i]);
  }
  ll ans = 1e18;
  for (int i = 0; i < n-1; i++) {
    add(p[i]+1, nax, -cost[i]);
    add(0, p[i]+1, cost[i]);
    ans = min(ans, mi[1]);
  }
  cout << ans << endl;
}