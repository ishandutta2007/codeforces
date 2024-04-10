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

int N, TT;
int T[3000], Q[3000];
vector<int> newOpts[3000];

int main() {
  scanf("%d%d", &N, &TT);
  REP(i,N) {
    scanf("%d%d", T+i, Q+i);
    newOpts[TT-T[i]].push_back(Q[i]);
  }
  
  vector<int> opts;
  FORD(lev,TT-1,0) {
    vector<int> nopts;
    for (int i = 0; i < (int)opts.size(); ++i) {
      if (i < (int)opts.size() - 1) {
        nopts.push_back(opts[i] + opts[i + 1]);
        ++i;
      } else {
        nopts.push_back(opts[i]);
      }
    }
    for (int q : newOpts[lev]) nopts.push_back(q);
    opts = nopts;
    sort(opts.begin(), opts.end());
    reverse(opts.begin(), opts.end());
  }
  
  printf("%d\n", opts[0]);
  
  return 0;
}