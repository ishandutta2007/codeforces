#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;
ll mypow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = (r*a)%mod;
    a = (a*a)%mod;
    p >>= 1;
  }
  return r;
}

vector<int> node[300000];
int done[300000];
int na, nb, fail;
void dfs(int p, int col = 1) {
  if (done[p]) {
    if (done[p] != col) fail = 1;
    return;
  }
  done[p] = col;
  if (col==1) na++;
  else nb++;
  for (int i : node[p]) dfs(i,3-col);
}

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      node[i].clear(), done[i] = 0;
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--,b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    ll ways = 1;
    for (int i = 0; i < n; i++) {
      if (done[i]) continue;
      na = nb = fail = 0;
      dfs(i);
      if (fail) ways = 0;
      ways = (ways*(mypow(2,na)+mypow(2,nb)))%mod;
    }
    cout << (ways%mod+mod)%mod << '\n';
  }
}