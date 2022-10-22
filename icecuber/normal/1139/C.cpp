#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];
ll mod = 1e9+7;
ll mypow(ll a, ll k) {
  ll r = 1;
  for (int i = 0; i < k; i++)
    r = r*a%mod;
  return r;
}

int done[100000];
int dfs(int p) {
  if (done[p]++) return 0;
  int r = 1;
  for (int i : node[p])
    r += dfs(i);
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    if (!c) {
      node[a].push_back(b);
      node[b].push_back(a);
    }
  }
  ll ans = mypow(n, k);
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    int s = dfs(i);
    ans = (ans-mypow(s, k))%mod;
  }
  cout << (ans+mod)%mod << endl;
}