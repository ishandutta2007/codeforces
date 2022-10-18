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

const int MAX = 400100;

struct Tournament {
  const llint inf = 1e18;
  const static int off = 1<<19;

  llint T[2*off];
  llint S[2*off];
  
  void init() {
    for (int i = 0; i < 2*off; ++i)
      T[i] = inf, S[i] = 0;
  }

  void propagate(int i) {
    int l = i*2, r = l+1;
    if (S[i]) {
      S[l] += S[i], S[r] += S[i];
      T[l] += S[i], T[r] += S[i];
      S[i] = 0;
    }
  }

  void merge(int i) {
    int l = i*2, r = l+1;
    if (T[l] < T[r]) T[i] = T[l] + S[i]; else
      T[i] = T[r] + S[i];
  }

  void add(int i, int lo, int hi, int a, int b, llint k) {
    if (lo >= b || hi <= a) return;
    if (lo >= a && hi <= b) { S[i] += k; T[i] += k; return; }
    propagate(i);

    add(i*2, lo, (lo+hi)/2, a, b, k);
    add(i*2+1, (lo+hi)/2, hi, a, b, k);

    merge(i);
  }
 
  void set(int x, llint v) {
    x += off;
    T[x] = v, S[x] = 0;

    for (int y = x/2; y; y /= 2)
      T[x] -= S[y];
    
    for (x /= 2; x; x /= 2)
      merge(x);
  }

  llint get(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return inf;
    if (lo >= a && hi <= b) return T[i];
    propagate(i);
    return min(get(i*2, lo, (lo+hi)/2, a, b), get(i*2+1, (lo+hi)/2, hi, a, b));
  }

  void add(int a, int b, llint k) {
    add(1, 0, off, a, b, k);
  }
  
  llint getmin(int a, int b) {
    return get(1, 0, off, a, b);
  }
} T;

vector<int> E[MAX];
int who1[MAX];
int who2[MAX];
int w1[MAX];
int w2[MAX];

int start[MAX], finish[MAX];
llint dep[MAX];
int t;

void dfs(int x) {
  start[x] = t++;
  for (int y: E[x]) {
    dep[y] = dep[x] + w1[y];
    dfs(y);
  }
  finish[x] = t++;
}

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);

  REP(i, 2*(n-1)) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    --a, --b;

    if (i < n-1) {
      E[a].push_back(b);
      who1[i] = b;
      w1[b] = w;
    } else {
      w2[a] = w;
      who2[i] = a;
    }
  }

  dfs(0);

  T.init();
  REP(i, n) T.set(start[i], dep[i] + w2[i]);

  auto getDep = [&] (int x) {
    return T.getmin(start[x], start[x] + 1) - w2[x];
  };
  
  REP(i, q) {
    int tip;
    scanf("%d", &tip);

    if (tip == 1) {
      int idx, w;
      scanf("%d %d", &idx, &w); --idx;

      if (idx < n-1) {
        int x = who1[idx];
        T.add(start[x], finish[x], w - w1[x]);
        w1[x] = w;
      } else {
        int x = who2[idx];
        T.add(start[x], start[x]+1, w - w2[x]);
        w2[x] = w;
      }
    } else {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;

      llint ans = 1e18;
      if (start[u] <= start[v] && finish[v] <= finish[u]) {
        ans = min(ans, getDep(v) - getDep(u));
      }

      ans = min(ans, T.getmin(start[u], finish[u]) - getDep(u) + getDep(v));
      printf("%lld\n", ans);
    }
  }
  return 0;
}