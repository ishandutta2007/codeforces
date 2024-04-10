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

const int MAX = 100100;
const int mod = 1e9 + 7;

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int dad[MAX];
vector<int> F[MAX], F2[MAX];
bool ima[MAX], gl[MAX];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  dad[findset(x)] = findset(y);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) dad[i] = i;
  REP(i, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a, --b;
    if (c == 1) merge(a, b); else {
      F[a].push_back(b);
      F[b].push_back(a);
    }
  }
  
  REP(x, n) gl[x] = findset(x) == x;
  REP(x, n)
    for (int y: F[x])
      F2[findset(x)].push_back(y);

  REP(x, n) {
    if (!gl[x] || F2[x].size() == 0) continue;
    int y = F2[x][0];
    for (int y2: F2[x]) merge(y, y2);
  }
  
  REP(x, n)
    for (int y: F[x])
      if (findset(x) == findset(y)) {
        puts("0");
        return 0;
      }
  
  REP(x, n)
    ima[findset(x)] |= F[x].size() > 0;
  
  int cnt = 0, cnt_no = 0;
  REP(x, n)
    if (findset(x) == x) {
      if (ima[x]) cnt++; else
        cnt_no++;
    }
  
  assert(cnt % 2 == 0);
  cnt /= 2;

  int ans = 1;
  REP(i, cnt + cnt_no - 1)
    ans = mul(ans, 2);
  printf("%d\n", ans);
  return 0;
}