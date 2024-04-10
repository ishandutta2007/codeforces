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

int N, K;

int main() {
  scanf("%d%d", &N, &K);
  int l = 1, h = N;
  char buf[100];
  while (l < h) {
    int m = (l + h) / 2;
    printf("1 %d %d\n", m, m+1);
    fflush(stdout);
    scanf(" ");
    gets(buf);
    if (buf[0] == 'T') {
      h = m;
    } else {
      l = m + 1;
    }
  }
  int x = l;
  l = x + 1;
  h = N;
  while (l < h) {
    int m = (l + h + 1) / 2;
    printf("1 %d %d\n", m, m-1);
    fflush(stdout);
    gets(buf);
    if (buf[0] == 'T') {
      l = m;
    } else {
      h = m - 1;
    }
  }
  int y = -1;
  if (l <= h) {
    printf("1 %d %d\n", l, x);
    fflush(stdout);
    gets(buf);
    if (buf[0] == 'T') {
      y = l;
    }
  }
  if (y == -1) {
    l = 1;
    h = x - 1;
    while (l < h) {
      int m = (l + h) / 2;
      printf("1 %d %d\n", m, m+1);
      fflush(stdout);
      gets(buf);
      if (buf[0] == 'T') {
        h = m;
      } else {
        l = m + 1;
      }
    }
    y = l;
  }
  printf("2 %d %d\n", x, y);
  return 0;
}