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

char action[22][22];
int t[22];
int a[110];
int ps[22];

int f[21][1<<20];
int bits[1<<20];

int main(void)
{
  int n, m;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  scanf("%d", &m);
  REP(i, m) scanf("%s %d", action[i], t+i);
  
  REP(i, m)
    ps[i+1] = ps[i] + (action[i][0] == 'p');
  
  sort(a, a + n, greater<int>());
  n = m;
 
  int p = (1<<n);
  for (int i = 1; i < p; ++i)
    bits[i] = bits[i>>1] + (i&1);

  for (int i = n-1; i >= 0; --i)
    REP(s, p) {
      if (bits[s] < ps[i] || bits[s] > i) continue;
      
      int fr = 0;
      while (s&(1<<fr)) fr++;

      if (action[i][0] == 'p') f[i][s] = (t[i] == 1 ? +a[fr] : -a[fr]) + f[i+1][s|(1<<fr)]; else {
        f[i][s] = f[i+1][s];
        while (fr < n) {
          if (!(s&(1<<fr))) {
            if (t[i] == 1) f[i][s] = max(f[i][s], f[i+1][s|(1<<fr)]); else
              f[i][s] = min(f[i][s], f[i+1][s|(1<<fr)]);
          }
          fr++;
        }
      }
    }

  printf("%d\n", f[0][0]);
  return 0;
}