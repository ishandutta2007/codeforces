#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef unsigned int uint;

const int MAXN = 2048;
const int MAX = 1<<16;

int first[MAX];

int getFirst(uint x) {
  if (x&(MAX-1)) return first[x&(MAX-1)];
  return 16+first[x>>16];
}

struct bitset {
  uint a[MAXN/32];
  int g = MAXN/32;
  void set(int x) { a[x>>5] |= (1U<<(x&31)); }
  int get(int x) { return (a[x>>5]>>(x&31))&1; }
};

int a[MAXN][MAXN];
bitset r[MAXN], c[MAXN];

short Q[MAXN*MAXN*2];
int head, tail;

void add(int i, int j) {
  a[i][j] = 1;
  Q[tail++] = i;
  Q[tail++] = j;
  r[i].set(j);
  c[j].set(i);
}

int main(void) {
  REP(i, (1<<16))
    first[i] = (i&1) ? 0 : first[i>>1] + 1;
  
  int n;
  scanf("%d", &n);
  REP(i, n) REP(j, n) {
    scanf("%d", a[i]+j);
    if (a[i][j]) add(i, j);
  }
  int g = MAXN/32;

  int cnt = 0;
  while (head < tail) {
    int i = Q[head++];
    int j = Q[head++];
    cnt++;

    REP(k, g) {
      if (r[j].a[k]&(~r[i].a[k])) {
        uint x = r[j].a[k]&(~r[i].a[k]);
        int f;
        while (x > 0) {
          f = getFirst(x);
          add(i, k*32 + f);
          x -= 1u<<f;
        }
      }
      if (c[i].a[k]&(~c[j].a[k])) {
        uint x = c[i].a[k]&(~c[j].a[k]);
        int f;
        while (x > 0) {
          f = getFirst(x);
          add(k*32 + f, j);
          x -= 1u<<f;
        }
      }
    }
  }
   
  if (cnt == n*n) puts("YES"); else
    puts("NO");
  return 0;
}