#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100010;
const int K = 100;

struct Edge {
  int a, b;
};

vector<int> E[MAXN];
vector<Edge> c[MAXN];
vector<int> v[MAXN];
int a[MAXN], cnt;
int id[MAXN];
int bio[MAXN];
int cookie;

int qu[MAXN], qv[MAXN];
pair<int, int> q[MAXN];
int ans[MAXN];

void dfs(int x) {
  bio[x] = cookie;
  a[cnt++] = x;
  for (int y: E[x])
    if (bio[y] != cookie) dfs(y);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b, col;
    scanf("%d %d %d", &a, &b, &col); --a, --b, --col;
    c[col].push_back({a, b});
    v[col].push_back(a);
    v[col].push_back(b);
  }

  int nq;
  scanf("%d", &nq);
  REP(i, nq) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    if (u > v) swap(u, v);
    q[i] = {u, v};
    qu[i] = u, qv[i] = v;
  }

  sort(q, q + nq);
  int uq = unique(q, q + nq) - q;

  REP(i, m) {
    sort(v[i].begin(), v[i].end());
    v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    cookie++;
    for (int x: v[i]) E[x].clear(), id[x] = -1;
    for (Edge &e: c[i]) {
      E[e.a].push_back(e.b);
      E[e.b].push_back(e.a);
    }
    
    for (int x: v[i])
      if (bio[x] != cookie) {
        cnt = 0;
        dfs(x);

        if (c[i].size() < K) {
          REP(p1, cnt) REP(p2, cnt)
            if (a[p1] < a[p2]) {
              pair<int, int> pr = {a[p1], a[p2]};
              int ind = lower_bound(q, q + uq, pr) - q;
              if (ind < uq && q[ind] == pr) ans[ind]++;
            }
        }
        
        REP(p1, cnt)
          id[a[p1]] = x;
      }

    if (c[i].size() >= K) {
      REP(j, uq)
        if (bio[q[j].first] == cookie && bio[q[j].second] == cookie)
          if (id[q[j].first] == id[q[j].second]) ans[j]++;
    }
  }
  
  REP(i, nq) {
    pair<int, int> pr = {qu[i], qv[i]};
    int ind = lower_bound(q, q + uq, pr) - q;
    printf("%d\n", ans[ind]);
  }
  
  return 0;
}