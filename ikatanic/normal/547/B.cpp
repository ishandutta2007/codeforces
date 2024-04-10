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

const int MAX = 202000;

int a[MAX];
int f[MAX];
int dad[MAX];
int sz[MAX];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  x = findset(x);
  y = findset(y);
  
  if (x == y) return;

  dad[y] = x;
  sz[x] += sz[y];
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  REP(i, n) dad[i] = -1;

  static vector<pair<int, int>> v;
  REP(i, n) v.push_back({a[i], i});
  sort(v.begin(), v.end());

  for (int i = (int)v.size()-1; i >= 0; --i) {
    int j = v[i].second;
    dad[j] = j, sz[j] = 1;
    
    if (j > 0 && dad[j-1] != -1) merge(j, j-1);
    if (j+1 < n && dad[j+1] != -1) merge(j, j+1);
    
    int size = sz[ findset(j) ];
    f[size] = max(f[size], v[i].first);
  }

  for (int i = n; i > 0; --i)
    f[i-1] = max(f[i-1], f[i]);

  for (int i = 1; i <= n; ++i)
    printf("%d ", f[i]);
  printf("\n");
  return 0;
}