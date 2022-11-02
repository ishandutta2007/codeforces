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

int N;
int A[4000];
int depth[4000];

int main() {
  scanf("%d", &N);
  int C = 2;
  REP(i,N) C *= 2;
  C -= 1;
  FOR(i,1,C-1) {
    scanf("%d", A+i);
  }

  REP(i,C) {
    depth[i] = A[i];
  }

  int ans = 0;
  FORD(i,(C-3)/2,0) {
    int c1 = 2*i+1;
    int c2 = 2*i+2;
    int diff = abs(depth[c1] - depth[c2]);
    depth[i] = max(depth[c1], depth[c2]) + A[i];
    ans += diff;
  }
  
  printf("%d\n", ans);

  return 0;
}