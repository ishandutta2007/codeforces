#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXQ = 150010;
const int MAXN = 50050;
const int S = 16;
const int Tp = 8;
const int T = 1<<Tp;

int a[MAXN];
int qu[MAXQ], qv[MAXQ], qans[MAXQ];
int d[MAXN], dad[MAXN], stk[MAXN], prv[MAXN];
vector<int> E[MAXN];

vector<int> es[MAXN];

void dfs(int x) {
  stk[d[x]] = x;
  if (d[x] >= T-1) {
    if (d[x] - T < 0) {
      prv[x] = -1;
    } else {
      prv[x] = stk[d[x] - T];
    }
  }
  
  for (int y: E[x]) {
    if (y != dad[x]) {
      dad[y] = x;
      d[y] = d[x] + 1;
      dfs(y);
    }
  }
}


int cnt[S][1<<S];
int mx[1<<S];

void add(int x, int k) {
  int r = x;
  x &= ~(T-1);

  if (k > 0) {
    mx[x] = max(mx[x], r);
  } else {
    mx[x] = 0;
  }
  
  FOR(j, Tp, S) {
    cnt[j][x] += k;
    x &= ~(1<<j);
  }
}

int findBest(int xorv) {
  int pre = 0;
  for (int j = S - 1; j >= Tp; --j) {
    int npre = pre;
    if ((xorv & (1<<j)) == 0) npre ^= 1<<j;

    if (cnt[j][npre]) pre = npre;
    else pre = npre ^ (1<<j);
  }
  return mx[pre] ^ xorv;
}

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dad[0] = -1;
  dfs(0);

  REP(i, q) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    qu[i] = u, qv[i] = v;

    int dist = 0;
    while (d[v] - (T-1) >= d[u]) {
      es[v].push_back(i);
      dist += T;
      v = prv[v];
    }

    while (v != -1 && d[v] >= d[u]) {
      qans[i] = max(qans[i], (a[v] ^ dist));
      v = dad[v];
      dist++;
    }
  }

  REP(i, n) {
    if (d[i] >= T-1) {
      int x = i;
      REP(j, T) {
        add(a[x]^j, 1);
        x = dad[x];
      }

      for (int j: es[i]) {
        qans[j] = max(qans[j], findBest(d[qv[j]] - d[i]));
      }

      x = i;
      REP(j, T) {
        add(a[x]^j, -1);
        x = dad[x];
      }
    }
  }
  
  REP(i, q) printf("%d\n", qans[i]);
  return 0;
}