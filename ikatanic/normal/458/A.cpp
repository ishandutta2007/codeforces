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

const int MAXN = 100010;
const double eps = 1e-10;

char a[MAXN];
char b[MAXN];

void answer(double w) {
  if (w < -eps) putchar('<'); else
    if (w > eps) putchar('>'); else
      putchar('=');
  exit(0);
}

int main(void) {
  scanf("%s", a);
  scanf("%s", b);
  int n = strlen(a);
  int m = strlen(b);

  reverse(a, a + n);
  reverse(b, b + m);
  
  while (m < n) b[m++] = '0';
  while (n < m) a[n++] = '0';
  while (n < 2) {
    a[n] = '0';
    b[n] = '0';
    n++;
  }

  REP(i, n) a[i] -= '0', b[i] -= '0';

  for (int i = n-1; i > 1; --i) {
    if (a[i] == b[i]) continue;

    if (a[i] > b[i]) {
      if (a[i]-b[i] > 1) answer(+1);
      a[i-2]++, a[i-1]++;
    } else
      if (a[i] < b[i]) {
        if (b[i]-a[i] > 1) answer(-1);
        b[i-2]++, b[i-1]++;
      }
  }
  
  if (a[1] == b[1]) answer(a[0]-b[0]);
  if (a[0] == b[0]) answer(a[1]-b[1]);

  double q = (1 + sqrt(5))/2;
  answer((a[1]-b[1])*q + (a[0]-b[0]));
  
  return 0;
}