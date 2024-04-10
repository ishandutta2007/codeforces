#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

char a[22][22];
int v[22][22];

int mask[26][42];
int f[40][1<<20];
bool bio[40][1<<20];

int n;

int solve(int k, int s) {
  if (bio[k][s]) return f[k][s];
  bio[k][s] = true;
    
  bool player = (k+1)&1;
  f[k][s] = player ? 10000 : -10000;
  
  int ns = 0;
  REP(j, n)
    if (s&(1<<j)) {
      if (j+1 < n) ns |= (1<<(j+1));
      if (k-j+1 < n) ns |= (1<<j);
    }

  REP(j, n)
    if (s&(1<<j)) {
      int i = k-j;
      if (i+1 < n) {
        int score = v[i+1][j] + solve(k+1, ns&mask[ a[i+1][j] ][k+1] );
        if (player) f[k][s] = min(f[k][s], score); else
          f[k][s] = max(f[k][s], score);
      }
      if (j+1 < n) {
        int score = v[i][j+1] + solve(k+1, ns&mask[ a[i][j+1] ][k+1] );
        if (player) f[k][s] = min(f[k][s], score); else
          f[k][s] = max(f[k][s], score);
      }
    }
  return f[k][s];
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n) {
    scanf("%s", a[i]);
    REP(j, n) {
      a[i][j] -= 'a';
      if (a[i][j] == 0) v[i][j] = 1; else
        if (a[i][j] == 1) v[i][j] = -1;
    }
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      mask[a[i][j]][i+j] |= 1<<j;

  bio[2*n-2][1<<(n-1)] = 1;
  f[2*n-2][1<<(n-1)] = 0;
  
  int ans = solve(0, 1) + v[0][0];
  if (ans > 0) puts("FIRST"); else
    if (ans < 0) puts("SECOND"); else
      puts("DRAW");
  
  return 0;
}