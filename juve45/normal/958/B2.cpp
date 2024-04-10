#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

int i, n, x, y, dist1[N], dist2[N], dist3[N], root, who[N], between[N], tata[N], rs;
bool viz[N];
vector<int> lda[N];
set<pair<int, int>> S;
queue<int> q;

void dfs(int x, int lvl, int *dist) {
  dist[x] = lvl; viz[x] = 1;
  for(auto to : lda[x]) if(!viz[to]) dfs(to, lvl + 1, dist);
}

void getInfo(int x) {
  viz[x] = 1; who[x] = x; between[x] = dist3[x];
  for(auto to : lda[x]) {
    if(viz[to]) continue;
    tata[to] = x; getInfo(to);
    if(between[to] > between[x]) between[x] = between[to], who[x] = who[to];
  }
  if(between[x] && !dist3[tata[x]]) S.insert(mp(between[x], who[x]));
}

void solve(int x) {
  if(!dist3[x]) return;
  for(auto to : lda[x]) {
    if(!dist3[to] || to == tata[x]) continue;
    S.erase(mp(between[to], who[to]));
    between[to] -= dist3[x];
    if(between[to]) S.insert(mp(between[to], who[to]));
  }
  dist3[x] = 0;
  solve(tata[x]);
}

int main() {
  scanf("%d", &n);
  if(n == 1) return 0 * puts("1");
  for(i = 1; i < n; ++i) {
    scanf("%d %d", &x, &y);
    lda[x].push_back(y);
    lda[y].push_back(x);
  }

  dfs(1, 1, dist2);
  for(i = 1; i <= n; ++i) if(dist2[i] > dist2[x]) x = i;
  memset(viz, 0, sizeof(viz));
  dfs(x, 1, dist1);
  for(i = 1; i <= n; ++i) if(dist1[i] > dist1[y]) y = i;
  memset(viz, 0, sizeof(viz));
  dfs(y, 1, dist2);

  printf("1 %d ", dist2[x]);

  for(rs = dist2[x], i = 1; i <= n; ++i) {
    if(dist1[i] + dist2[i] - 1 == dist2[x]) q.push(i);
    else dist3[i] = INF;
    if(dist2[i] == (dist2[x] + 1) / 2) root = i;
  }

  for(; !q.empty(); q.pop()) {
    int now = q.front();
    for(auto to : lda[now])
      if(dist3[to] > dist3[now] + 1) {
        dist3[to] = dist3[now] + 1;
        q.push(to);
      }
  }

  memset(viz, 0, sizeof(viz));
  getInfo(x);

  for(i = 3; i <= n; ++i) {
    if(!S.size() || rs == n) {
      printf("%d ", n);
      continue;
    }
    //for(auto it : S) printf("(%d, %d) ", it.fi, it.se);
    //puts("");
    int now = S.rbegin()->se;
    rs += S.rbegin()->fi;
    rs = min(rs, n);
    S.erase(*S.rbegin());
    printf("%d ", rs);
    solve(now);
  }

  return 0;
}