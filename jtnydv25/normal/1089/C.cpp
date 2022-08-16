#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 501;
const int INF = 1000;

bool vis[N];
bool allowed[N];
int bestU, mn;
string status;
int n;
vi g[N];
int D[N][N];

int f(int x, int y) {
  int res = 0;
  rep(i,1,n+1) if(allowed[i]) {
    res += D[y][i] < D[x][i];
  }
  return res;
}

void mark(int x, int y) {
  rep(i,1,n+1) if(allowed[i]) {
    // printf("%d %d %d\n",i,D[x][i], D[y][i]);
    if(D[y][i] >= D[x][i]) {
      allowed[i] = false;
    }
  }
}

queue<int > q;
void pre() {
  rep(i,1,n+1) if(allowed[i]) {
    q.push(i);
    rep(j,1,n+1) if(allowed[j]) {
      D[i][j] = INF;
    }
    D[i][i] = 0;
    while(q.size()) {
      int c = q.front();
      q.pop();
      rep(j,0,g[c].size()) {
        int u = g[c][j];
        if(!allowed[u]) continue;
        if(D[i][u] > D[i][c] + 1) {
          D[i][u] = D[i][c] + 1;
          q.push(u);
        }
      }
    }
  }
}

void dfs(int c) {
  vis[c] = true;
  // do pair wise bfs for c.
  int mx = 0;
  rep(i,0,g[c].size()) {
    int u = g[c][i];
    if(!allowed[u]) continue;
    mx = max(mx, f(c, u));
  }

  if(mx < mn) {
    mn = mx;
    bestU = c;
  }

  // go to other vertices
  rep(i,0,g[c].size()) {
    int u = g[c][i];
    if(vis[u] || !allowed[u]) continue;
    dfs(u);
  }
}

int main() {
  int m;
  S2(n,m);
  while(m--) {
    int k;
    S(k);
    int p = -1;
    rep(i,0,k) {
      int x;
      S(x);
      if(p != -1) {
        g[p].pb(x);
        g[x].pb(p);
      }
      p = x;
    }
  }

  rep(itr,0,n) {

    rep(i,1,n+1) {
      allowed[i] = true;
    }

    int st = 1;
    while(1) {
      memset(vis, false, sizeof(vis));
      bestU = -1, mn = n + 1;
      pre();
      dfs(st);
      assert(bestU != -1);
      cout << bestU << "\n";
      fflush(stdout);
      cin >> status;
      if(status == "FOUND") {
        break;
      }
      int w;
      cin >> w;
      st = w;
      mark(bestU, w);
      allowed[bestU] = false;
    }
  }
  return 0;
}