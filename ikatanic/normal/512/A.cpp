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

const int MAXN = 110;

char a[MAXN];
string s[MAXN];

bool e[MAXN][MAXN];
bool bio[MAXN];
int indeg[MAXN];

vector<int> v;

void dfs(int x) {
  if (bio[x]) return;
  bio[x] = true;
  REP(i, 26)
    if (e[x][i]) dfs(i);
  v.push_back(x);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%s", a);
    s[i] = a;
  }
  
  REP(j, n) REP(i, j) {
    int k = 0;
    while (k < (int)s[i].size() && k < (int)s[j].size() && s[i][k] == s[j][k]) k++;
    if (k == (int)s[i].size()) continue;
    if (k == (int)s[j].size()) { puts("Impossible"); return 0; }
    e[ s[i][k]-'a' ][ s[j][k]-'a'] = true;
    indeg[ s[j][k]-'a' ]++;
  }

  REP(i, 26)
    if (indeg[i] == 0) dfs(i);
  
  if (v.size() != 26) { puts("Impossible"); return 0; }
  
  reverse(v.begin(), v.end());
  REP(i, 26) putchar(v[i] + 'a');
  putchar('\n');
  return 0;
}