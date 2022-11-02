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

int zeros = 0;
int ones = 0;

int main() {
  scanf("%d%d", &N, &K);
  REP(i,N) {
    int a;
    scanf("%d", &a);
    if (a % 2) ++ones;
    else ++zeros;
  }
  int turns = N - K;
  if (turns == 0) {
    printf("%s\n", (ones % 2 == 1) ? "Stannis" : "Daenerys");
    return 0;
  }
  bool oddGoesLast = turns % 2 != 0;
  bool oddWinsIfZerosDeleted = (ones - (turns - zeros)) % 2 != 0;

  bool oddWins;
  if (oddGoesLast) {
    if (oddWinsIfZerosDeleted) {
      if ((turns + 1) / 2 >= zeros) {
        oddWins = true;
      } else {
        if ((turns - 1) / 2 >= ones) {
          oddWins = false;
        } else {
          oddWins = true;
        }
      }
    } else {
      if ((turns - 1) / 2 >= min(ones, zeros)) {
        oddWins = false;
      } else {
        oddWins = true;
      }
    }
  } else {
    if (oddWinsIfZerosDeleted) {
      if (turns / 2 >= zeros) {
        oddWins = true;
      } else {
        oddWins = false;
      }
    } else {
      oddWins = false;
    }
  }
  printf("%s\n", oddWins ? "Stannis" : "Daenerys");
  return 0;
}