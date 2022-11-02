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

int N, M;

char input[200][200];

bool isFace(int x, int y) {
  bool hasF = false;
  bool hasA = false;
  bool hasC = false;
  bool hasE = false;
  REP(dx, 2) REP(dy, 2) {
    switch (input[y+dy][x+dx]) {
      case 'f': hasF = true; break;
      case 'a': hasA = true; break;
      case 'c': hasC = true; break;
      case 'e': hasE = true; break;
      default: break;
    }
  }
  return hasF && hasA && hasC && hasE;
}

int main() {
  scanf("%d%d ", &N, &M);
  REP(i,N) {
    gets(input[i]);
  }
  int cnt = 0;
  REP(y,N-1) REP(x,M-1) {
    if (isFace(x, y)) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
  return 0;
}