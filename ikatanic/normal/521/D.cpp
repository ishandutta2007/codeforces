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

const int MAXN = 100100;

llint a[MAXN];
vector<int> v[MAXN], vm[MAXN], vs[MAXN];

int t[MAXN], id[MAXN], b[MAXN];

llint num[MAXN], denom[MAXN];
int who[MAXN];
int k, n, m;

struct cmp {
  bool operator () (const int &x, const int &y) {
    if (num[x]*denom[y] != num[y]*denom[x])
      return num[x]*denom[y] > num[y]*denom[x];
    return x < y;
  }
};

set<int, cmp> S;

void update(int i) {
  int c = v[i].back(), cm = vm[i].back();
  num[i] = b[c], denom[i] = a[i], who[i] = c;
  if ((b[cm]-1) * a[i] > b[c]) num[i] = b[cm]-1, denom[i] = 1, who[i] = cm;
  if (who[i] < n) S.insert(i);
}

int main(void) {
  scanf("%d %d %d", &k, &n, &m);
  REP(i, k) scanf("%lld", a+i);
  REP(i, n) {
    scanf("%d %d %d", t+i, id+i, b+i);
    --id[i];
    if (t[i] == 1) {
      b[i] -= a[id[i]];
      vs[id[i]].push_back(i);
    } else
      if (t[i] == 2) v[id[i]].push_back(i); else
        vm[id[i]].push_back(i);
  }

  t[n] = 2, b[n] = 0;
  t[n+1] = 3, b[n+1] = 1;

  REP(i, k) {
    v[i].push_back(n);
    vm[i].push_back(n+1);
  }

  REP(i, k) {
    auto f = [&] (const int &x, const int &y) {
      return b[x] < b[y];
    };

    sort(vs[i].begin(), vs[i].end(), f);
    if (vs[i].size()) v[i].push_back(vs[i].back());

    sort(v[i].begin(), v[i].end(), f);
    sort(vm[i].begin(), vm[i].end(), f);
    update(i);
  }

  vector<int> ans;
  while (S.size() && (int)ans.size() < m) {
    int i = *S.begin();
    S.erase(S.begin());

    int j = who[i];
    ans.push_back(j);

    if (t[j] == 3) {
      assert(vm[i].back() == j);
      vm[i].pop_back();
    } else {
      assert(v[i].back() == j);
      v[i].pop_back();
      a[i] += b[j];
    }
    
    update(i);
  }

  sort(ans.begin(), ans.end(), [&] (const int &i, const int &j) {
      return t[i] < t[j];
    }
  );

  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x+1);
  printf("\n");
  return 0;
}