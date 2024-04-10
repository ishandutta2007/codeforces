#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int > par;
#define t first
#define k second

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

char c[41];
int s[41][41];
int w[41][41];

bool f[41][41][41][41];
int g[41][41][41][41];

int main(void)
{
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  REP(i, n) {
    scanf("%s", c);
    s[i][0] = w[i][0] = 0;
    REP(j, m) {
      int v = c[j]-'0';
      s[i][j+1] = s[i][j] + v;
      w[i][j+1] = (w[i][j] + 1-v)*(1-v);
    }
  }

  REP(d, m) REP(b, d+1) REP(a, n) {
    for (int c = a; c < n; ++c) {
      if (s[c][d+1] - s[c][b] > 0) break;
      f[a][b][c][d] = 1;
    }
  }
  
  for (int a = 0; a < n; ++a)
    for (int b = 0; b < m; ++b)
      for (int c = a; c < n; ++c)
        for (int d = b; d < m; ++d) {
          int &r = g[a][b][c][d];
          r = 0;
          if (a == c) {
            for (int x = b; x <= d; ++x)
              for (int y = x; y <= d; ++y)
                r += f[a][x][c][y];
            continue;
          }
          if (b == d) {
            for (int x = a; x <= c; ++x)
              for (int y = x; y <= c; ++y)
                r += f[x][b][y][d];
            continue;
          }

          r = g[a][b][c][d-1];

          static stack<par> S;
          while (!S.empty()) S.pop();
          int sum = 0;
          for (int x = a; x <= c; ++x) {
            if (w[x][d+1] == 0) {
              while (!S.empty()) S.pop();
              sum = 0;
              continue;
            }
            
            int t = min(d-b+1, w[x][d+1]), k = 1;
            while (!S.empty() && t <= S.top().t) k += S.top().k, sum -= S.top().t*S.top().k, S.pop();
            S.push(make_pair(t, k));
            sum += t*k;
            r += sum;
          }
          
        }

  REP(i, q) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    --a, --b, --c, --d;
    printf("%d\n", g[a][b][c][d]);
  }
  return 0;
}