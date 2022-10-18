#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> par;

const int MAXN = 100100;
const int mod = 1e9 + 9;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int x[MAXN], y[MAXN];
vector<int> e[MAXN], f[MAXN];
bool bio[MAXN];

map<par, int> M;
set<int> S;

bool good(int i) {
  for (int j: f[i])
    if (!bio[j]) {
      int cnt = 0;
      for (int k: e[j])
        cnt += !bio[k];
      if (cnt == 1) return false;
    }
  return true;
}
    
int main(void) {
  int m;
  scanf("%d", &m);
  REP(i, m) {
    scanf("%d %d", x+i, y+i);
    M[{x[i], y[i]}] = i;
  }

  REP(i, m)
    for (int dx = -1; dx <= +1; ++dx) {
      int X = x[i] + dx, Y = y[i] + 1;
      if (M.count({X, Y})) {
        e[M[{X, Y}]].push_back(i);
        f[i].push_back(M[{X, Y}]);
      }
    }

  REP(i, m) 
    if (good(i)) S.insert(i);
  
  int ans = 0;
  bool p = false;
  while (S.size()) {
    int i = -1;
    if (!p) i = *(--S.end()); else
      i = *S.begin();
    p ^= 1;

    S.erase(i);
    ans = add(mul(ans, m), i);
    bio[i] = true;

    for (int j: e[i]) 
      if (!bio[j] && good(j)) S.insert(j);

    for (int j: f[i]) 
      for (int k: e[j]) 
        if (!bio[k] && !good(k)) S.erase(k);
  }

  printf("%d\n", ans);
  return 0;
}