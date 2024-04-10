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

const int MAX = 202000;

struct frac {
  llint A, B;
  friend bool operator < (const frac& a, const frac& b) {
    return a.A * b.B > b.A * a.B;
  }
};

int l[MAX], p[MAX], k[MAX];
frac nx[MAX], pr[MAX];

int main(void) {
  int n, t, q;
  scanf("%d %d %d", &n, &t, &q);
  REP(i, n) scanf("%d", &p[i]);
  REP(i, n) scanf("%d", &l[i]);

  set<pair<frac, int>> prev, next;
  auto calc = [&] (int x, int k) {
    return (frac){p[x]*l[x], llint(l[x] + k) * (l[x] + k + 1)};
  };

  REP(i, n) {
    k[i] = 0;
    nx[i] = calc(i, k[i]);
    next.insert({nx[i], i});
  }
  
  double score = 0;
  int cnt = 0;
  auto take = [&] (int x) {
    next.erase(next.find({nx[x], x}));
   
    if (k[x] > 0) prev.erase(prev.find({pr[x], x}));
    score += double(nx[x].A) / nx[x].B;

    k[x]++;
    pr[x] = calc(x, k[x] - 1);
    nx[x] = calc(x, k[x]);

    prev.insert({pr[x], x});
    if (k[x] + 1 <= l[x]) next.insert({nx[x], x});
    cnt++;

  };

  auto release = [&] (int x) {
    prev.erase(prev.find({pr[x], x}));

    if (k[x] + 1 <= l[x]) next.erase(next.find({nx[x], x}));
    score -= double(pr[x].A) / pr[x].B;

    k[x]--;
    pr[x] = calc(x, k[x] - 1);
    nx[x] = calc(x, k[x]);

    if (k[x] > 0) prev.insert({pr[x], x});
    if (k[x] + 1 <= l[x]) next.insert({nx[x], x});
    cnt--;
  };

  while (cnt < t && next.size()) take(next.begin()->second);

  REP(i, q) {
    int tk, x;
    scanf("%d %d", &tk, &x); --x;
    tk = tk == 1 ? +1 : -1;

    score -= double(p[x])*k[x] / (l[x] + k[x]);
    l[x] += tk;

    if (k[x] > 0) {
      prev.erase(prev.find({pr[x], x}));
      pr[x] = calc(x, k[x] - 1);
      prev.insert({pr[x], x});
    }

    if (k[x] + 1 <= l[x] - tk) {
      assert(next.find({nx[x], x}) != next.end());
      next.erase(next.find({nx[x], x}));
    }
    
    if (k[x] + 1 <= l[x]) {
      nx[x] = calc(x, k[x]);
      next.insert({nx[x], x});
    }

    score += double(p[x])*k[x] / (l[x] + k[x]);
  
    if (k[x] > l[x]) {
      assert(k[x]-1 == l[x]);
      release(x);
    }

    while (k[x] > 0 && next.size()) {
      auto it = next.begin();
      if (it->second == x) {
        if (next.size() == 1) break;
        it++;
      }
      if (it->first < pr[x]) {
        release(x);
        take(it->second);
      } else break;
    }

    while (cnt < t && next.size()) take(next.begin()->second);

    while (k[x] + 1 <= l[x] && prev.size()) {
      auto it = --prev.end();
      if (it->second == x) {
        if (prev.size() == 1) break;
        --it;
      }

      if (nx[x] < it->first) {
        release(it->second);
        take(x);
      } else break;
    }

    printf("%.10lf\n", score);
  }
  return 0;
}