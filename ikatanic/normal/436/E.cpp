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
typedef pair<int, int> par;

const int MAXN = 300030;
const int off = 1<<20;
const llint inf = 1e18;

int a[MAXN], b[MAXN];
int id[MAXN][2];
int T[2*off];
llint S[2*off];
int V[2*off];
int cnt[MAXN];

llint query(int i, int k) {
  if (i >= off) return (k == 1) * S[i];
  if (k <= T[i*2]) return query(i*2, k);
  return S[i*2] + query(i*2+1, k - T[i*2]);
}

void flip(int x) {
  x += off;
  T[x] ^= 1;
  S[x] = T[x] * V[x];
  for (x /= 2; x; x /= 2) {
    T[x] = T[x*2] + T[x*2+1];
    S[x] = S[x*2] + S[x*2+1];
  }
}

int main(void) {
  int n, w;
  scanf("%d %d", &n, &w);
  vector<par> v, vb;
  REP(i, n) {
    scanf("%d %d", a+i, b+i);
    v.push_back({a[i], 2*i});
    v.push_back({b[i] - a[i], 2*i+1});
    vb.push_back({b[i], i});
  }

  sort(vb.begin(), vb.end());
  sort(v.begin(), v.end());
  REP(i, (int)v.size()) {
    id[v[i].second/2][v[i].second&1] = i;
    V[off+i] = v[i].first;
  }
  REP(i, n) flip(id[i][0]);

  llint ans = inf;
  llint cur = 0;
  int besti = -1;
  for (int i = 0; i <= n && i <= w; ++i) {
    if (T[1] >= w-i) {
      llint cost = cur + query(1, w-i);
      if (cost < ans) {
        ans = cost;
        besti = i;
      }
    }

    if (i < n) {
      int x = vb[i].second;
      flip(id[x][0]);
      flip(id[x][1]);
      cur += a[x];
    }
  }

  vector<par> va;
  REP(i, besti) {
    int x = vb[i].second;
    cnt[x]++;
    va.push_back({b[x] - a[x], x});
  }
  FOR(i, besti, n) {
    int x = vb[i].second;
    va.push_back({a[x], x});
  }

  sort(va.begin(), va.end());
  REP(i, w - besti)
    cnt[va[i].second]++;

  printf("%lld\n", ans);
  REP(i, n) printf("%d", cnt[i]);
  printf("\n");
  return 0;
}