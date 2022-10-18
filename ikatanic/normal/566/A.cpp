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

const int MAX = 1e6;

char s[MAX];
int t[MAX][26];
int cnt[MAX];
int ans1[MAX], ans2[MAX];
vector<int> v[MAX];

int alloc = 1;

void insert(int x, char* s, int idx) {
  v[x].push_back(idx);
  if (!*s) return;
  int c = *s - 'a';
  if (!t[x][c]) t[x][c] = alloc++;
  cnt[t[x][c]]++;
  insert(t[x][c], s + 1, idx);
}

int solve(int x, int y) {
  int ans = min(cnt[x], cnt[y]);
  REP(i, 26)
    if (t[x][i] && t[y][i]) ans += solve(t[x][i], t[y][i]);
  
  int i = 0, j = 0;
  while (i < (int)v[x].size() && j < (int)v[y].size()) {
    if (ans1[v[x][i]]) { i++; continue; }
    if (ans2[v[y][j]]) { j++; continue; }
    ans1[v[x][i]] = v[y][j];
    ans2[v[y][j]] = v[x][i];
    i++, j++;
  }
  return ans;
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  int root1 = alloc++;
  REP(i, n) {
    scanf("%s", s);
    insert(root1, s, i+1);
  }
  int root2 = alloc++;
  REP(i, n) {
    scanf("%s", s);
    insert(root2, s, i+1);
  }
  
  printf("%d\n", solve(root1, root2));
  REP(i, n) printf("%d %d\n", i+1, ans1[i+1]);
  return 0;
}