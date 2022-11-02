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
char A[1000];

int main() {
  scanf("%d ", &N);
  gets(A);
  bool good = false;
  REP(i,N) FOR(l,1,N-1) {
    if (i >= N || A[i] != '*') continue;
    bool ok = true;
    int at = i;
    REP(j,4) {
      at += l;
      if (at >= N || A[at] != '*') {
        ok = false;
        break;
      }
    }
    if (ok) {
      good = true;
    }
  }
  printf("%s\n", good ? "yes" : "no");
  return 0;
}