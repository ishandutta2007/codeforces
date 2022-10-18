#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXT = 24*60*60;
const int MAXN = 20020;

set<int> st[MAXT+10], en[MAXT+10];

vector<int> E[MAXN];
int a[MAXN];
int l[MAXN], r[MAXN];
int dad[MAXN];
int ans[MAXN];

struct cmp {
  bool operator () (const int &a, const int &b) {
    if (r[a] != r[b]) return r[a] > r[b];
    return a < b;
  }
};

set<int, cmp> S;

void dfs(int x, int a) {
  ans[x] = a;
  for (int y: E[x])
    dfs(y, a);
}

int main(void) {
  int n, m, T;
  scanf("%d %d %d", &n, &m, &T);
  REP(i, n) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    a[i] = (h*60 + m)*60 + s;
    st[a[i]].insert(i);
    en[a[i]+T].insert(i);
    l[i] = a[i], r[i] = a[i] + T;
    dad[i] = i;
  }

  bool ok = false;
  REP(i, MAXT) {
    for (int j: st[i]) S.insert(j);
    for (int j: en[i]) if (r[j] == i) S.erase(j);
    
    while ((int)S.size() > m) {
      int x = *S.begin(); S.erase(S.begin());
      int y = *S.begin(); S.erase(S.begin());
      
      en[r[x]].erase(x);
      en[r[y]].erase(y);

      E[x].push_back(y);
      dad[y] = x;
      r[x] = max(r[x], r[y]);
      en[r[x]].insert(x);
      S.insert(x);
    }

    ok |= (int)S.size() == m;
  }

  if (!ok) {
    puts("No solution");
    return 0;
  }

  int R = 0;
  REP(i, n)
    if (dad[i] == i) {
      dfs(i, R);
      R++;
    }

  printf("%d\n", R);
  REP(i, n) printf("%d\n", ans[i]+1);
  return 0;
}