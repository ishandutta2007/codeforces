#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

typedef pair<int, int> par;

const int MAXN = 300300;
const int MAX = 70;

int b[MAXN];

int main(void)
{
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", b+i);
  
  static par a[MAXN];
  REP(i, n) a[i] = {b[i], i};

  sort(a, a + n, greater<par>());
  
  static set<int> S;
  double ans = 0;

  REP(i, n) {
    int x = a[i].first, pos = a[i].second;
    auto it = S.lower_bound(pos);
    
    static int l[MAX];
    int nl = 0;
    auto itl = it;
    while (nl < MAX && itl != S.begin()) l[nl++] = *(--itl);
    int last = pos;
    REP(i, nl) l[i] = last-l[i], last -= l[i];
    if (nl < MAX) l[nl++] = last-0+1;

    static int r[MAX];
    int nr = 0;
    auto itr = it;
    while (nr < MAX && itr != S.end()) r[nr++] = *(itr++);
    last = pos;
    REP(i, nr) r[i] = r[i]-last, last += r[i];
    if (nr < MAX) r[nr++] = n-last;
    
    double suml = 0, p2 = 1;
    REP(i, nl) suml += l[i]/p2, p2 *= 2;
    double sumr = 0; p2 = 1;
    REP(i, nr) sumr += r[i]/p2, p2 *= 2;
    
    ans += suml*sumr*x/2.0/n;
    S.insert(pos);
  }
  
  ans /= n;
  printf("%lf\n", ans);
  return 0;
}