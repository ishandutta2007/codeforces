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

const int W = 310;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
            
bool bio[W][W];
unsigned char f[W][W];
unsigned char nf[W][W];

int main(void) {
  int x = W/2, y = W/2;
  int n;
  scanf("%d", &n);

  f[x][y] |= 1<<0;

  REP(i, n) {
    int t;
    scanf("%d", &t);

    REP(j, t) {
      REP(x, W) REP(y, W) {
        if (f[x][y]) {
          REP(d, 8) {
            if (f[x][y] & (1<<d)) {
              if (i > 0 && j == 0) {
                int d1 = (d + 1) % 8;
                int d2 = (d + 7) % 8;
                nf[x + dx[d1]][y + dy[d1]] |= 1<<d1;
                nf[x + dx[d2]][y + dy[d2]] |= 1<<d2;
              } else {
                nf[x + dx[d]][y + dy[d]] |= 1<<d;
              }
            }
          }
        }
      }

      REP(x, W) REP(y, W) {
        f[x][y] = nf[x][y];
        nf[x][y] = 0;
        bio[x][y] |= f[x][y] > 0;
      }
    }
  }

  int ans = 0;
  REP(x, W) REP(y, W) ans += bio[x][y];
  printf("%d\n", ans);
  return 0;
}