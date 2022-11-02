#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 10;

int N;
int B[MAXN];
int E[MAXN];

int main() {
  scanf("%d", &N);
  REP(i,N) {
    scanf("%d%d", B+i, E+i);
    ++E[i];
  }

  vector<double> p;
  FOR(res,1,10000) {
    REP(i,N) REP(j,N) if (i != j) {
      if (res < B[j] || res >= E[j]) continue;
      double r = 1;
      double q;
      q = E[i] - max(B[i], res + (i > j));
      if (q < 0.5) r = 0;
      r *= q;
      REP(k,N) if (k != i && k != j) {
        q = min(E[k], res + (k > j)) - B[k];
        if (q < 0.5) r = 0;
        r *= q;
      }
      if (r != 0) {
        p.push_back(r * res);
      }
      //DEBUG(res);
      //DEBUG(i);
      //DEBUG(j);
      //DEBUG(r);
      //DEBUG("=====");
    }
  }
  sort(p.begin(), p.end());
  double a = 0;
  REP(i,(int)p.size()) {
    a += p[i];
  }
  double b = 1;
  REP(i,N) b *= E[i] - B[i];
  printf("%.15lf\n", a/b);

  return 0;
}