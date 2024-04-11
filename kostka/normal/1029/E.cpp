//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 200007;
int d[MAXN], pre[MAXN];
bool odw[MAXN];
vi G[MAXN];

void dfs(int v) {
  odw[v] = true;
  for(auto w : G[v]) if(!odw[w]) {
    d[w] = d[v] + 1;
    pre[w] = v;
    dfs(w);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  set <pii> S;
  for(int i=1; i<=n; i++) {
    if(d[i] > 2) {
      S.emplace(d[i], i);
    }
  }
  int res = 0;
  while(!S.empty()) {
    auto it = prev(S.end());
    res++;
    int v = pre[(*it).second];
    S.erase(make_pair(d[v], v));
    for(auto w : G[v]) {
      if(S.find(make_pair(d[w], w)) != S.end()) {
        S.erase(make_pair(d[w], w));
      }
    }
  }
  cout << res << "\n";
  return 0;
}