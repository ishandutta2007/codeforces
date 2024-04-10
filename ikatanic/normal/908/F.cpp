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

llint range(vector<llint>& A) {
  if (A.size() == 0) return 0;
  return A.back() - A[0];
}

llint max_gap(vector<llint>& A) {
  assert((int)A.size() >= 2);
  llint r = A[1] - A[0];
  for (int i = 1; i < (int)A.size(); ++i) {
    r = max(r, A[i] - A[i-1]);
  }
  return r;
}

int main(void) {
  int n;
  scanf("%d", &n);

  vector<pair<llint, char>> v;
  vector<llint> G, B, R;

  REP(i, n) {
    llint x;
    char s[3];
    scanf("%lld %s", &x, s);
    v.push_back({x, s[0]});

    if (s[0] == 'G') G.push_back(x);
    if (s[0] == 'B') B.push_back(x);
    if (s[0] == 'R') R.push_back(x);
  }

  if (G.size() == 0) {
    llint ret = range(B) + range(R);
    printf("%lld\n", ret);
    return 0;
  }

  llint ret = 0;

  llint first = G[0];
  int i = 0;
  llint max_b = 0, max_r = 0;
  while (v[i].first < first) {
    if (v[i].second == 'B') max_b = max(max_b, first - v[i].first);
    if (v[i].second == 'R') max_r = max(max_r, first - v[i].first);
    i++;
  }

  ret += max_b + max_r;
  assert(v[i].first == first);
  i++;

  for (int j = 1; j < (int)G.size(); ++j) {
    llint cur = G[j];
    llint prev = G[j-1];

    vector<llint> b, r;
    b.push_back(prev);
    r.push_back(prev);
    while (v[i].first < cur) {
      if (v[i].second == 'B') b.push_back(v[i].first);
      if (v[i].second == 'R') r.push_back(v[i].first);
      i++;
    }
    assert(v[i].first == cur);
    i++;

    b.push_back(cur);
    r.push_back(cur);

    llint max_b = cur - prev - max_gap(b);
    llint max_r = cur - prev - max_gap(r);
    if (max_b > 0 && max_r > 0) {
      ret += min(2*(cur - prev), max_b + max_r + cur - prev);
    } else {
      ret += max_b + max_r + cur - prev;
    }
  }

  llint last = G.back();
  max_b = 0, max_r = 0;
  while (i < (int)v.size()) {
    if (v[i].second == 'B') max_b = max(max_b, v[i].first - last);
    if (v[i].second == 'R') max_r = max(max_r, v[i].first - last);
    i++;
  }

  ret += max_b + max_r;

  printf("%lld\n", ret);
  return 0;
}