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
#define ALL(X) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 200007;
int dis[MAXN];
vector <pii> G[MAXN];
vi E[MAXN];

void bfs(int s) {
  queue <int> Q;
  Q.push(s);
  dis[s] = 1;
  while(!Q.empty()) {
    int v = Q.front();
    Q.pop();
    for(auto ele : G[v]) {
      int w = ele.x;
      if(!dis[w]) {
        dis[w] = dis[v] + 1;
        Q.push(w);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }
  bfs(1);
  for(int i=2; i<=n; i++) {
    for(auto ele : G[i]) {
      if(dis[ele.x] == dis[i] - 1) {
        E[i].push_back(ele.y);
      }
    }
  }
  vector <string> A;
  string ans;
  for(int i=0; i<m; i++) ans += '0';
  function<void(int)> foo = [&](int i) {
    if(SZ(A) == k) return;
    if(i == n+1) {
      A.push_back(ans);
      return;
    }
    for(int j=0; j<SZ(E[i]); j++) {
      ans[E[i][j]] = '1';
      foo(i+1);
      ans[E[i][j]] = '0';
    }
  };
  foo(2);
  cout << SZ(A) << "\n";
  for(auto a : A) cout << a << "\n";
  return 0;
}