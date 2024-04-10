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
vector<string> A;
vector<string> AA;
vector<string> out;

int main() {
  scanf("%d ", &N);
  REP(i,N) {
    char buff[2*N+100];
    gets(buff);
    A.push_back(buff);
  }
  {
    string row;
    REP(j,2*N-1) {
      row += 'x';
    }
    REP(i,2*N-1) {
      out.push_back(row);
    }
    out[N-1][N-1] = 'o';
  }
  REP(i,N) {
    string row;
    REP(j,N) {
      char c = A[i][j];
      row += c == 'o' ? c : '.';
    }
    AA.push_back(row);
  }

  REP(y1, N) REP(y2, N) REP(x1, N) REP(x2, N) {
    char p1 = A[y1][x1];
    char p2 = A[y2][x2];
    if (p1 != 'o') continue;
    if (p2 != '.') continue;
    int pdy = N + y2 - y1 - 1;
    int pdx = N + x2 - x1 - 1;
    out[pdy][pdx] = '.';
  }

  REP(y1, N) REP(y2, N) REP(x1, N) REP(x2, N) {
    char p1 = A[y1][x1];
    char p2 = A[y2][x2];
    if (p1 != 'o') continue;
    if (p2 == 'o') continue;
    int pdy = N + y2 - y1 - 1;
    int pdx = N + x2 - x1 - 1;
    if (out[pdy][pdx] != 'x') continue;
    AA[y2][x2] = 'x';
  }

  if (A == AA) {
    printf("YES\n");
    REP(i,2*N-1) {
      printf("%s\n", out[i].c_str());
    }
  } else {
    printf("NO\n");
  }
  return 0;
}