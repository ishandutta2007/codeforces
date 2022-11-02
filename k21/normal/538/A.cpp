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

char A[1000];
char T[] = "CODEFORCES";
int N, TN;

int main() {
  gets(A);
  N = strlen(A);
  TN = strlen(T);
  int b = 0;
  while (b < N && A[b] == T[b]) ++b;
  int e = 0;
  while (e < N && A[N-e-1] == T[TN-e-1]) ++e;
  printf("%s\n", b + e >= TN ? "YES" : "NO");
  return 0;
}