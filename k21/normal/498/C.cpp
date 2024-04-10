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

const int MAXN = 200;
const int MAXX = 32*MAXN;

const int INF = 1<<29;
typedef long long ll;

int N, M;
int A[MAXX];
int B[MAXX];
int A_cnt = 0, B_cnt = 0;
vector<int> edges[MAXX];
vector<int> Amap[MAXN], Bmap[MAXN];
int matches[MAXX];
bool visited[MAXX];

vector<int> getFactors(int n) {
  vector<int> result;
  int i = 2;
  while (i*i <= n) {
    while (n % i == 0) {
      result.push_back(i);
      n /= i;
    }
    ++i;
  }
  if (n != 1) result.push_back(n);
  return result;
}

bool find_match(int from) {
  if (from == -1) {
    return true;
  }
  for (int match : edges[from]) {
    if (!visited[match]) {
      visited[match] = true;
      if (find_match(matches[match])) {
        matches[match] = from;
        return true;
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &N, &M);
  REP(i,N) {
    int x;
    scanf("%d", &x);
    for (int factor : getFactors(x)) {
      if (i % 2) {
        Bmap[i].push_back(B_cnt);
        B[B_cnt++] = factor;
      } else {
        Amap[i].push_back(A_cnt);
        A[A_cnt++] = factor;
      }
    }
  }
  REP(i,M) {
    int a,b;
    scanf("%d%d", &a, &b);
    --a; --b;
    if (a % 2) swap(a,b);
    for (int from : Amap[a]) for (int to : Bmap[b]) {
      if (A[from] == B[to]) {
        edges[from].push_back(to);
      }
    }
  }
  int ans = 0;
  REP(i,MAXX) matches[i] = -1;
  REP(i,A_cnt) {
    REP(j,MAXX) visited[j] = false;
    ans += find_match(i);
  }
  printf("%d\n", ans);
  return 0;
}