#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

double angle[MAXN];

int x[MAXN], y[MAXN];
bool bio[MAXN];

vector<int> E[MAXN];
map<int, int> flow[MAXN], sum[MAXN];

int dfs(int x) {
  if (bio[x]) return 0;
  bio[x] = true;
  int ans = 1;
  for (int y: E[x]) {
    int d = dfs(y);
    ans += d;
    flow[x][y] = -d;
    flow[y][x] = +d;
  }
  return ans;
}

double calcAngle(int i, int j) {
  return atan2(y[j]-y[i], x[j]-x[i]);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  int k = 0;
  REP(i, n) {
    scanf("%d %d", x+i, y+i);
    if (x[i] < x[k]) k = i;
  }
  
  int s = n++;
  x[s] = x[k]-1, y[s] = y[k];
  E[s].push_back(k);
  E[k].push_back(s);
  
  dfs(s);
  
  REP(i, n) {
    for (int j: E[i])
      angle[j] = calcAngle(i, j);
    sort(E[i].begin(), E[i].end(), [] (int a, int b) { return angle[a] < angle[b]; });
    int cur = 0;
    for (int j: E[i]) {
      cur += flow[i][j];
      sum[i][j] = cur;
    }
  }
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    
    static int v[MAXN];
    REP(i, k) {
      scanf("%d", v+i);
      --v[i];
    }

    llint area = 0;
    REP(i, k) {
      int a = v[0], b = v[(i+1)%k], c = v[(i+2)%k];
      area += llint(x[b]-x[a])*(y[c]-y[a]) - llint(y[b]-y[a])*(x[c]-x[a]);
    }
    if (area < 0) reverse(v, v + k);
    
    int ans = 0;
    REP(i, k) {
      int a = v[i], b = v[(i+1)%k], c = v[(i+2)%k];
      if (calcAngle(b, a) < calcAngle(b, c)) {
        ans += sum[b][c] - sum[b][a] - flow[b][c];
      } else {
        ans += 1 - sum[b][a] + sum[b][c] - flow[b][c];
      }
    }

    printf("%d\n", ans);
  }    
  return 0;
}