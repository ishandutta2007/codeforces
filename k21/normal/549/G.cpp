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
ll A[1000000];
ll mmp[1000000];
ll out[1000000];

int main() {
  scanf("%d", &N);
  REP(i,N) scanf("%I64d", A+i);
  reverse(A, A+N);
  REP(i,N) mmp[i] = A[i] - i;
  sort(mmp, mmp+N);
  reverse(mmp, mmp+N);
  REP(i,N) {
    out[i] = mmp[i] + i;
    if (out[i] < 0 || (i > 0 && out[i] > out[i-1])) {
      printf(":(\n");
      return 0;
    }
  }
  reverse(out, out+N);
  REP(i,N) printf("%I64d%c", out[i], i == N-1 ? '\n' : ' ');
  return 0;
}