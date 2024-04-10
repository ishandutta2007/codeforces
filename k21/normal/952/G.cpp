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
  string line;
  getline(cin, line);
  int st = 0;
  for (int ch : line) {
    if (st <= ch) st += 256;
    int cnt = st-ch;
    REP(i,cnt) {
      printf("X.");
    }
    REP(i,256-cnt) {
      printf("..");
    }
    st = ch;
    printf("\nX.");
    REP(i,255) printf("..");
    printf("\n");
    REP(i,256) printf("..");
    printf("\n");
  }
  return 0;
}