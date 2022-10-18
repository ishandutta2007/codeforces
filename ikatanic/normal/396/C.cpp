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

const int mod = 1e9 + 7;
const int MAXN = 300300;

int Lv[MAXN], Lk[MAXN];

void add(int &a, int b) {
  if ((a += b) >= mod) a -= mod;
}

void add(int x, int v, int k) {
  for (++x; x < MAXN; x += x&-x)
    add(Lv[x], v), add(Lk[x], k);
}

int get(int x, int d) {
  int v = 0, k = 0;
  for (++x; x; x -= x&-x)
    add(v, Lv[x]), add(k, Lk[x]);
  v -= (llint(k)*d)%mod;
  if (v < 0) v += mod;
  return v;
}

int tick = 0;
int s[MAXN], f[MAXN];
int d[MAXN], dad[MAXN];
vector<int> E[MAXN];

void dfs(int x) {
  s[x] = tick++;
  for (int y: E[x]) {
    d[y] = d[x] + 1;
    dfs(y);
  }
  f[x] = tick;
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", dad+i); --dad[i];
    E[dad[i]].push_back(i);
  }

  d[0] = 0;
  dfs(0);
  
  int q;
  scanf("%d", &q);
  REP(i, q) {
    int z;
    scanf("%d", &z);
    if (z == 1) {
      int x, v, k;
      scanf("%d %d %d", &x, &v, &k); --x;
      v = (v + llint(k)*d[x])%mod;

      add(s[x], v, k);
      add(f[x], (mod-v)%mod, (mod-k)%mod);
    } else {
      int x;
      scanf("%d", &x); --x;
      printf("%d\n", get(s[x], d[x]));
    }
  }
  return 0;
}