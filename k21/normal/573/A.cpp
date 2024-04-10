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
int A[100100];

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  scanf("%d", &N);
  REP(i,N) scanf("%d", A+i);
  int g = A[0];
  REP(i,N) g = gcd(g, A[i]);
  REP(i,N) A[i] /= g;
  REP(i,N) {
    int n = A[i];
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    if (n != 1) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}