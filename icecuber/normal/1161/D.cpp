#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;

vector<pair<int,int>> node[3000];
void reset() {
  for (int i = 0; i < 3000; i++) node[i].clear();
}
void addEdge(int a, int b, int c) {
  node[a].push_back({b,c});
  node[b].push_back({a,c});
}

int done[3000];
int col[3000];
int dfs(int p, int c) {
  if (col[p] != -1 && col[p] != c)
    return 1;
  if (done[p]++) return 0;
  col[p] = c;
  for (auto e : node[p])
    if (dfs(e.first, c ^ e.second)) return 1;
  return 0;
}

ll countWays(int n) {
  fill_n(done, n, 0);
  fill_n(col, n, -1);
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    if (dfs(i, 1)) return 0;
    ans += ans;
    if (ans >= mod) ans -= mod;
  }
  return ans*((mod+1)/2)%mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  ll ans = 0;
  for (int la = 1; la < n; la++) {
    reset();
    for (int i = 0; i < n/2; i++)
      addEdge(i, n-1-i, 0);
    for (int i = 0; i < la/2; i++)
      addEdge(n+i, n+la-1-i, 0);
    addEdge(n+la-1, n*2, 1);
    for (int i = 0; i < n; i++) {
      if (s[i] != '?')
	addEdge(i, n+i, s[i]-'0');
      if (i >= la)
	addEdge(n+i, n*2, 0);
    }
    (ans += countWays(n*2+1)) %= mod;
  }
  cout << ans << endl;
}