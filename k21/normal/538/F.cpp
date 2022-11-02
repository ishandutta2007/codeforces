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
vector<int> A;

map<int, vector<int>> memo;
int getCountFast(int lim, int b, int e) {
  auto it = memo.find(lim);
  if (it == memo.end()) {
    it = memo.insert({lim, vector<int>()}).first;
    vector<int>& v = it->second;
    v.push_back(0);
    REP(i,N) {
      v.push_back(v.back() + (A[i] < lim));
    }
  }
  const vector<int>& v = it->second;
  return v[e] - v[b];
}

int getCount(int k) {
  int cnt = 0;
  REP(i,N) {
    int b = i * k + 1;
    int e = min(b + k, N);
    if (k < 450) {
      FOR(j,b,e-1) {
        if (A[i] > A[j]) {
          ++cnt;
        }
      }
    } else {
      cnt += getCountFast(A[i], b, e);
    }
    if (e >= N) break;
  }
  return cnt;
}

int main() {
  scanf("%d", &N);
  REP(i,N) {
    int a;
    scanf("%d", &a);
    A.push_back(a);
  }
  
  FOR(k,1,N-1) {
    printf("%d%c", getCount(k), k == N-1 ? '\n' : ' ');
  }
  
  return 0;
}