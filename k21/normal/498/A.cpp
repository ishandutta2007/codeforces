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

const int MAXN = 400;

ll X1, Y1, X2, Y2;
int N;
ll A[MAXN], B[MAXN], C[MAXN];

int main() {
  {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    X1 = x1; Y1 = y1; X2 = x2; Y2 = y2;
  }
  scanf("%d", &N);
  REP(i,N) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    A[i] = a; B[i] = b; C[i] = c;
  }
  
  int ans = 0;
  REP(i,N) {
    bool p1 = A[i]*X1 + B[i]*Y1 + C[i] > 0;
    bool p2 = A[i]*X2 + B[i]*Y2 + C[i] > 0;
    ans += (p1 != p2);
  }
  printf("%d\n", ans);
  return 0;
}