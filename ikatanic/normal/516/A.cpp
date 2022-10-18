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

char a[22];
int cnt[10];
int f[10][10];


int main(void) {
  FOR(i, 2, 10) {
    FOR(j, 2, i+1) {
      int x = j;
      for (int k = 2; k <= j; ++k)
        while (x%k == 0) {
          x /= k;
          f[i][k]++;
        }
    }
  }

  int n;
  scanf("%d", &n);
  scanf("%s", a);
  REP(i, n) {
    int c = a[i] - '0';
    REP(j, 10) cnt[j] += f[c][j];
  }

  int p7 = cnt[7];
  int p5 = cnt[5] - p7; 
  REP(i, 10)
    cnt[i] -= p7 * f[7][i] + p5 * f[5][i];

  assert(cnt[2] >= cnt[3]);
  int p3 = cnt[3];
  int p2 = cnt[2] - cnt[3];

  REP(i, p7) putchar('7');
  REP(i, p5) putchar('5');
  REP(i, p3) putchar('3');
  REP(i, p2) putchar('2');
  putchar('\n');
  return 0;
}