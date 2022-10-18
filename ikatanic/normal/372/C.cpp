#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 150005;

struct monotoni {
  llint q[MAXN], v[MAXN], k, p;
  void clear() { k = p = 0; }
  void push(int x, llint w) {
    v[x] = w;
    while (k > p && w >= v[q[k-1]]) k--;
    q[k++] = x;
  }
  void pop(int x) {
    if (k > p && q[p] == x) p++;
  }
  llint getmax() { return v[q[p]]; }
} Q;

vector<int> e[MAXN], f[MAXN];

llint dp[2][MAXN];
int a[MAXN], b[MAXN], t[MAXN];
int n, m, d;

int main(void)
{
  scanf("%d %d %d", &n, &m, &d);
  REP(i, m) {
    scanf("%d %d %d", a+i, b+i, t+i);
    --a[i];
  }

  e[0].push_back(0), f[n-1].push_back(0);
  REP(i, m) {
    int now = i&1, prev = now^1;
    Q.clear();
    REP(j, n) {
      for (int x : e[j]) Q.push(x, dp[prev][x]);
      dp[now][j] = Q.getmax() + b[i] - abs(a[i]-j);
      for (int x : f[j]) Q.pop(x);
      e[j].clear(), f[j].clear();
    }
    
    if (i == m-1) continue;

    int ld = min(llint(n), llint(d)*(t[i+1]-t[i]));
    REP(j, n) {
      int l = max(0, j-ld);
      int r = min(n-1, j+ld);
      e[l].push_back(j);
      f[r].push_back(j);
    }
                  
  }

  int now = (m-1)&1;
  llint ans = dp[now][0];
  REP(i, n) ans = max(ans, dp[now][i]);
  cout << ans << endl;
  return 0;
}