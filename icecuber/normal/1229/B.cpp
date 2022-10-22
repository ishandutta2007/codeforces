#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];
ll x[100000];

ll ans = 0;
map<ll,int> dfs_slow(int p, int par = -1) {
  map<ll,int> r;
  r[x[p]]++;
  ans += x[p];
  for (int i : node[p]) {
    if (i == par) continue;
    map<ll,int> m = dfs_slow(i,p);
    ll v = m.rbegin()->first;
    if (__gcd(v, x[p]) == v) continue;
    for (auto&it : m) {
      ll g = __gcd(it.first, x[p]);
      ans += g*it.second;
      r[g] += it.second;
    }
  }
  return r;
}

ll mod = 1e9+7;

void dfs(int p, int par = -1, map<ll,int> path = {}) {
  map<ll,int> cur;
  path[0]++;
  for (auto i : path) {
    ll g = __gcd(i.first, x[p]);
    cur[g] += i.second;
    (ans += g*i.second) %= mod;
  }
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p, cur);
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  cout << ans << endl;
}