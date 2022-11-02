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
ll cnt[200][200];

void update(int mx, int my, ll d) {
  REP(y,my+1) REP(x,mx+1) {
    cnt[y][x] += d;
  }
}

int main() {
  scanf("%d%d ", &N, &M);
  REP(i,N) gets(input[i]);
  int total = 0;
  FORD(y,N-1,0) FORD(x,M-1,0) {
    char c = input[y][x];
    ll exp = c == 'W' ? 1 : -1;
    if (exp != cnt[y][x]) {
      update(x, y, exp - cnt[y][x]);
      ++total;
    }
  }
  printf("%d\n", total);
  return 0;
}