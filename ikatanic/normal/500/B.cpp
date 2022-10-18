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

const int MAXN = 330;

int a[MAXN];
char s[MAXN][MAXN];
bool bio[MAXN];
int n;

void dfs(int i, vector<int> &v) {
  if (bio[i]) return;
  bio[i] = true;
  v.push_back(i);
  REP(j, n)
    if (s[i][j] == '1') dfs(j, v);
}

int main(void) {
    scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  REP(i, n) scanf("%s", s[i]);
  
  REP(i, n)
    if (!bio[i]) {
      vector<int> v;
      dfs(i, v);
      
      vector<int> w;
      for (int x: v) w.push_back(a[x]);
      sort(v.begin(), v.end());
      sort(w.begin(), w.end());
      REP(j, (int)v.size()) a[v[j]] = w[j];
    }

  REP(i, n) printf("%d ", a[i]);
  printf("\n");
  return 0;
}