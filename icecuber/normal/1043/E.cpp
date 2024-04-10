#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll y[300000];
ll xy[300000];
vector<int> node[300000];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  ll sumy = 0;
  vector<ll> v, w;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x >> y[i];
    xy[i] = x-y[i];
    node[i].push_back(i);
    sumy += y[i];
    v.push_back(xy[i]);
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  sort(v.begin(), v.end());
  w.push_back(0);
  for (int i = 0; i < n; i++)
    w.push_back(w[i]+v[i]);
  for (int i = 0; i < n; i++) {
    ll r = n*y[i]+sumy;
    ll k = upper_bound(v.begin(), v.end(), xy[i])-v.begin();
    r += w[k]+xy[i]*(n-k);

    for (int j : node[i]) {
      r -= y[i]+y[j]+min(xy[i], xy[j]);
    }
    cout << r << ' ';
  }
  cout << endl;
}