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

void recon(char *s, int p, int c, int a, int n) {
  s[n] = '\0';
  REP(i, n) s[i] = 'B';
  if (c) s[0] = 'C';
  if (a) s[n-1] = 'A';
  REP(i, p)
    s[c+i*2] = 'A', s[c+i*2+1] = 'C';
}

int main(void)
{
  int k, x, n, m;
  scanf("%d %d %d %d", &k, &x, &n, &m);
  
  for (int c1 = 0; c1 <= 1; ++c1)
    for (int a1 = 0; a1 <= 1; ++a1) 
      for (int p1 = 0; a1+c1+p1*2 <= n; ++p1)
        for (int c2 = 0; c2 <= 1; ++c2)
          for (int a2 = 0; a2 <= 1; ++a2) 
            for (int p2 = 0; a2+c2+p2*2 <= m; ++p2) {
              static int p[55], c[55], a[55];
              p[1] = p1, c[1] = c1, a[1] = a1;
              p[2] = p2, c[2] = c2, a[2] = a2;

              bool ok = true;
              for (int i = 3; i <= k; ++i) {
                p[i] = p[i-2] + p[i-1] + a[i-2]*c[i-1];
                c[i] = c[i-2];
                a[i] = a[i-1];
                if (p[i] > x) { ok = false; break; }
              }

              if (ok && p[k] == x) {
                static char s1[110], s2[110];
                recon(s1, p1, c1, a1, n);
                recon(s2, p2, c2, a2, m);
                puts(s1);
                puts(s2);
                exit(0);
              }
            }

  puts("Happy new year!");
  return 0;
}