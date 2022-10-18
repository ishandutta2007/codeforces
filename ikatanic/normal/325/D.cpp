#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <bitset>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 3030;
const int MAXM = 6060;

int dad[MAXN*MAXM];
bool black[MAXN][MAXM];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  dad[findset(x)] = findset(y);
}

int main(void) {
  int r, c, q;
  scanf("%d %d %d", &r, &c, &q); c *= 2;
  REP(i, r) REP(j, c) dad[i*c+j] = i*c+j;
  
  int ans = 0;
  REP(i, q) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;

    vector<int> s1, s2;
    for (int dx = -1; dx <= 1; ++dx)
      for (int dy = -1; dy <= 1; ++dy) {
        int X = x + dx, Y = (y + dy + c) % c;
        if (X < 0 || X >= r) continue;
        if (black[X][Y]) s1.push_back(X*c + Y);

        Y = (y + dy + c + c/2) % c;
        if (black[X][Y]) s2.push_back(X*c + Y);
      }
    
    bool ok = false;
    for (int a: s1)
      for (int b: s2)
        if (findset(a) == findset(b)) {
          ok = true;
          break;
        }
    
    if (ok || c == 2) continue;

    black[x][y] = black[x][y + c/2] = true;

    int k1 = x*c + y;
    int k2 = x*c + y + c/2;

    for (int a: s1) merge(k1, a);
    for (int b: s2) merge(k2, b);
    ans++;
  }
  
  printf("%d\n", ans);
  
  return 0;
}