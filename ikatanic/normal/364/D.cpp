#include <algorithm>
#include <iostream>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1000001;
const int MAX = 1e7;

llint a[MAXN];

int d[MAXN], ad[MAXN];
int di[MAXN], adi[MAXN];


llint pr[20];
int pot[20];
int cnt, m;

llint gcd(llint a, llint b) { return !b ? a : gcd(b, a%b); }

void incDivs(int i, llint div, llint y, llint x, int add) {
  if (i == cnt) {
    if (div < m) ad[div] += add; else
      adi[x/div] += add;
    return;
  }

  llint w = 1;
  while (y%w == 0) {
    incDivs(i+1, div*w, y, x, add);
    w *= pr[i];
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%I64d", a+i);
  
  int h = (n+1)/2;
  int k = min(h+1, MAX/n);
  
  srand(time(0));
  random_shuffle(a, a + n);
  llint ans = 1;
  REP(p, k) {
    llint x = a[p];
    m = 1;
    while (llint(m)*m <= x) m++;

    cnt = 0;
    for (int j = 2; j < m; ++j)
      if (x%j == 0) {
        pot[cnt] = 0;
        while (x%j == 0) x /= j, pot[cnt]++;
        pr[cnt++] = j;
      }
    if (x > 1) pr[cnt] = x, pot[cnt++] = 1;
    x = a[p];

    for (int i = p; i < n; ++i) {
      llint g = gcd(x, a[i]);
      if (g < m) d[g]++; else
        di[x/g]++;
    }
    
    for (int i = 1; i < m && ans*i < x; ++i) {
      if (di[i]+adi[i] >= h) ans = x/i;
      if (di[i]) incDivs(0, 1, x/i, x, di[i]);
    }
    for (int i = m-1; i > ans; --i) {
      if (d[i]+ad[i] >= h) ans = i;
      if (d[i]) incDivs(0, 1, i, x, d[i]);
    }

    REP(i, m) d[i] = di[i] = ad[i] = adi[i] = 0;
  }  

  printf("%I64d\n", ans);
  return 0;
}