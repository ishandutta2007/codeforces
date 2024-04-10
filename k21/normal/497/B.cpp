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

const int MAXN = 100100;

int N;
int A[MAXN];
int p1 = 0, p2 = 0;

map<int, int> p2t1;
map<int, int> p2t2;
map<int, int> t2p1;
map<int, int> t2p2;

int getS(int t) {
  int s = 0;
  int os = 0;
  int base1 = 0, base2 = 0;
  while (base1 < p1) {
    if (base1 + t > p1) return 0;
    int at1 = p2t1[base1 + t];
    int at2;
    if (base2 + t > p2) {
      at2 = INF;
    } else {
      at2 = p2t2[base2 + t];
    }
    if (at2 < at1) {
      ++os;
      base1 = t2p1[at2];
      base2 = t2p2[at2];
    } else {
      ++s;
      base1 = t2p1[at1];
      base2 = t2p2[at1];
    }
  }
  return (base1 == p1 && base2 == p2 && s > os) ? s : 0;
}

int main() {
	scanf("%d", &N);
  REP(i,N) scanf("%d", A+i);
  
  if (A[N-1] != 1) REP(i,N) A[i] = 3-A[i];
  
  REP(i,N) {
    if (A[i] == 1) {
      ++p1;
      p2t1[p1] = i;
    } else {
      ++p2;
      p2t2[p2] = i;
    }
    t2p1[i] = p1;
    t2p2[i] = p2;
  }

  vector<pair<int, int>> solutions;
  FOR(t,1,N) {
    int s = getS(t);
    if (s) solutions.push_back({s, t});
  }
  sort(solutions.begin(), solutions.end());

  printf("%d\n", (int)solutions.size());
  for (const auto& p : solutions) {
    printf("%d %d\n", p.first, p.second);
  }
  
	return 0;
}