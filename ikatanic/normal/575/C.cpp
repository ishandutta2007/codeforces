#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 20;
const int inf = 1e9;
const int bad = 1<<26;

unsigned char mem[(1<<19) * 7];

int read(int s) {
  int i = (s / 2) * 7;
  if (s & 1) {
    i += 3;
    return ((mem[i]&15)<<24) + (mem[i+1]<<16) + (mem[i+2]<<8) + mem[i+3];
  } else {
    return (mem[i]<<20) + (mem[i+1]<<12) + (mem[i+2]<<4) + (mem[i+3]>>4);
  }
}

void write(int s, int x) {
  int i = (s / 2) * 7;
  if (s & 1) {
    i += 3;
    mem[i] &= ~15;
    mem[i] |= x>>24;
    mem[i+1] = (x>>16) & 255;
    mem[i+2] = (x>>8) & 255;
    mem[i+3] = x & 255;
  } else {
    mem[i] = (x>>20) & 255;
    mem[i+1] = (x>>12) & 255;
    mem[i+2] = (x>>4) & 255;
    mem[i+3] &= 15;
    mem[i+3] |= (x&255) << 4;
  }
}

void relax(int s, int nv) {
  int cur = read(s);
  if (nv > cur || cur == bad) write(s, nv);
}

int a[2][MAX][MAX];
int bc[1<<10], fr[1<<10];

inline int popcount(int x) {
  return bc[x>>10] + bc[x&1023];
}

inline int first(int x) {
  if (fr[x&1023] != -1) return fr[x&1023];
  if (fr[x>>10] != -1) return fr[x>>10] + 10;
  return -1;
}

int solve(int n) {
  REP(i, n/2+1) {
    REP(s, 1<<n) {
      int d = popcount(s);
      int cc = read(s);      
      if (cc == bad) continue;

      int cs = ~s & ((1<<n)-1), j;
      while ((j = first(cs)) != -1) {
        cs &= ~(1<<j);
        relax(s | (1<<j), cc + a[0][d][j]);
      }
    }
    if (i < n/2) {
      for (int s = (1<<n)-1; s >= 0; --s) {
        int d = popcount(s);
        int cc = read(s);
        if (cc == bad) continue;

        int cs = ~s & ((1<<n)-1), j;
        while ((j = first(cs)) != -1) {
          cs &= ~(1<<j);
          relax(s | (1<<j), cc + a[1][d][j]);
        }
        write(s, bad);
      }
    }
  }
  return read((1<<n)-1);
}

int main(void) {
  fr[0] = -1;
  FOR(i, 1, 1<<10) {
    bc[i] = bc[i>>1] + (i&1);
    if (i&1) fr[i] = 0; else
      fr[i] = 1 + fr[i>>1];
  }

  int n;
  scanf("%d", &n);
  REP(c, 2) REP(i, n) REP(j, n) scanf("%d", &a[c][i][j]);
  printf("%d\n", solve(n));
  return 0;
}