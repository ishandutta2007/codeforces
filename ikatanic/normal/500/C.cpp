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

const int MAXN = 1010;

bool bio[MAXN];
int w[MAXN], b[MAXN];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", w+i);
  vector<int> v;
  REP(i, k) {
    scanf("%d", b+i);
    --b[i];
    if (!bio[b[i]]) v.push_back(b[i]);
    bio[b[i]] = true;
  }

  int ans = 0;
  REP(i, k) {
    int pos = 0;
    REP(j, (int)v.size()) {
      if (v[j] == b[i]) { pos = j; break; }
      ans += w[v[j]];
    }

    v.erase(v.begin() + pos);
    v.insert(v.begin(), b[i]);
  }

  printf("%d\n", ans);
  return 0;
}