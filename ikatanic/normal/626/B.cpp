#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 222;

bool bio[MAX][MAX][MAX];
char s[MAX];
string ans;

void dfs(int c1, int c2, int c3) {
  if (bio[c1][c2][c3]) return;
  
  bio[c1][c2][c3] = true;
  if (c1 + c2 + c3 == 1) {
    if (c1 == 1) ans.push_back('R');
    if (c2 == 1) ans.push_back('G');
    if (c3 == 1) ans.push_back('B');
    return;
  }

  if (c1 > 0 && c2 > 0) dfs(c1-1, c2-1, c3+1);
  if (c1 > 0 && c3 > 0) dfs(c1-1, c2+1, c3-1);
  if (c2 > 0 && c3 > 0) dfs(c1+1, c2-1, c3-1);
  if (c1 > 1) dfs(c1-1, c2, c3);
  if (c2 > 1) dfs(c1, c2-1, c3);
  if (c3 > 1) dfs(c1, c2, c3-1);
}

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);

  int c1 = 0, c2 = 0, c3 = 0;
  REP(i, n) {
    if (s[i] == 'R') c1++;
    else if (s[i] == 'G') c2++;
    else c3++;
  }

  dfs(c1, c2, c3);
  sort(ans.begin(), ans.end());
  puts(ans.c_str());
  return 0;
}