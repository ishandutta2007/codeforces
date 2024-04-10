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

int main() {
  int n;
  int a[100];
  scanf("%d", &n);
  REP(i,n) scanf("%d", a+i);
  bool ok = true;
  while (n) {
    REP(i,n-1) {
      if (abs(a[i] - a[i+1]) >= 2) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    int best_i = 0;
    REP(i,n) {
      if (a[i] > a[best_i]) best_i = i;
    }
    FOR(i,best_i,n-2) {
      a[i] = a[i+1];
    }
    --n;
  }
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}