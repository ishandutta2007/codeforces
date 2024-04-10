#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <unordered_set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 55;

char a[MAX][33], b[MAX][33];
int n, q, ans;

unordered_set<string> S;

void dfs(string s) {
  if (S.count(s)) return;
  S.insert(s);
  if ((int)s.size() == n) { ans++; return; }

  REP(i, q)
    if (s[0] == b[i][0]) {
      string t = s;
      t[0] = a[i][1];
      t.insert(t.begin(), a[i][0]);
      dfs(t);
    }
}

int main(void) {
  scanf("%d %d", &n, &q);
  REP(i, q) scanf("%s %s", a[i], b[i]);

  dfs("a");
  printf("%d\n", ans);
  return 0;
}