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
typedef unsigned int uint;

const int MAXN = 70070;

int ind[1<<16];

int getIndex(uint x) {
  assert(x == (x&-x));
  return (x >= (1<<16)) ? 16+ind[x>>16] : ind[x];
}

struct bitset {
  uint a[MAXN/32];
  int g = MAXN/32;

  void shl(int k) {
    int p = k/32, q = k%32;
    if (q)
      for (int i = g-1; i >= 0; --i) {
        if (i+1 < g) a[i+1] |= a[i]>>(32-q);
        a[i] <<= q;
      }
    for (int i = g-1; i >= 0; --i)
      a[i] = (i-p >= 0) ? a[i-p] : 0;
  }

  void invert() {
    REP(i, g)
      a[i] = ~a[i];
  }

  void operator &= (const bitset &b) {
    REP(i, g)
      a[i] &= b.a[i];
  }
  
  void operator |= (const bitset &b) {
    REP(i, g)
      a[i] |= b.a[i];
  }
  
  void getOnes(vector<int> &v) {
    v.clear();
    REP(i, g) {
      uint x = a[i];
      while (x > 0) {
        v.push_back(i*32 + getIndex(x&-x));
        x -= x&-x;
      }
    }
  }

  void set(int x) { a[x>>5] |= (1U<<(x&31)); }
  int get(int x) { return (a[x>>5]>>(x&31))&1; }
};

vector<int> E[MAXN];

int r[MAXN], a[MAXN];
bool b[MAXN];

bitset dp, newdp, tmp;

int main(void)
{
  ind[1] = 0;
  for (int i = 2; i < (1<<16); ++i)
    ind[i] = (i&1) ? 0 : 1+ind[i>>1];

  int n, s;
  scanf("%d %d", &n, &s);
 
  int m = 0;
  REP(i, n) {
    scanf("%d", a+i);
    if (a[i] > a[m]) m = i;
  }
  
  r[a[m]] = m;
  dp.set(a[m]);

  REP(i, n) {
    int x = a[i];
    if (i == m) continue;

    newdp = dp;
    tmp = dp;
    
    newdp.shl(x);
    tmp.invert();
    newdp &= tmp;
    dp |= newdp;
    
    static vector<int> v;
    newdp.getOnes(v);
    for (int x : v)
      if (x <= s) r[x] = i;
  }
  
  if (dp.get(s) == 0) { puts("-1"); return 0; }

  while (s > 0) {
    b[r[s]] = true;
    s -= a[r[s]];
  }
  
  assert(s == 0);
  assert(b[m]);

  static vector<pair<int, int>> v;
  REP(i, n)
    if (!b[i]) v.push_back(make_pair(a[i], i));

  sort(v.begin(), v.end(), greater<pair<int, int>>());  
  for (int i = 0; i+1 < (int)v.size(); ++i)
    E[v[i].second].push_back(v[i+1].second);
  if (v.size()) E[m].push_back(v[0].second);

  REP(i, n) {
    int c = a[i];
    for (int x : E[i])
      c -= a[x];
    printf("%d %d", c, (int)E[i].size());
    for (int x : E[i])
      printf(" %d", x+1);
    printf("\n");
  }
  
  return 0;
}