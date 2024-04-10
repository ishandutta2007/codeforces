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
int A[500];
ll clen[500], cdist[500];

ll getGcd(ll a, ll b) {
  if (b == 0) return a;
  return getGcd(b, a % b);
}

ll getScm(ll a, ll b) {
  return a * b / getGcd(a, b);
}

void walk(int a0) {
  set<int> visited;
  vector<int> order;
  int a = a0;
  while (!visited.count(a)) {
    visited.insert(a);
    order.push_back(a);
    a = A[a];
  }
  int f = a;
  clen[a0] = 1;
  while (order.back() != f) {
    order.pop_back();
    ++clen[a0];
  }
  cdist[a0] = order.size() - 1;
}

int main() {
  scanf("%d", &N);
  
  REP(i, N) {
    scanf("%d", A+i);
    --A[i];
  }
  
  ll scm = 1;
  ll dist = 0;
  REP(i,N) {
    walk(i);
    scm = getScm(scm, clen[i]);
    dist = max(dist, cdist[i]);
  }
  
  ll ans = scm;
  while (ans < dist) ans += scm;
  
  printf("%I64d\n", ans);
  
  return 0;
}