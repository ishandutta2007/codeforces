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


vector<vector<double>> swapTimes(const vector<vector<double>>& p) {
  vector<vector<double>> total(N, vector<double>(N, 0.0));
  double cnt = 0;
  REP(b,N) FOR(e,b+1,N) {
    vector<vector<double>> t = p;
    REP(i, (e-b)/2) REP(j,N) {
      swap(t[j][b+i], t[j][e-i-1]);
    }
    REP(i, (e-b)/2) REP(j,N) {
      swap(t[b+i][j], t[e-i-1][j]);
    }
    REP(i,N) REP(j,N) {
      total[i][j] += t[i][j];
    }
    cnt += 1;
  }
  REP(i,N) REP(j,N) {
    total[i][j] /= cnt;
  }
  return total;
}

int main() {
  scanf("%d%d", &N, &K);

  vector<int> p;
  REP(i,N) {
    int a;
    scanf("%d", &a);
    p.push_back(a);
  }
  vector<vector<double>> s(N, vector<double>(N, 0));
  REP(i,N) REP(j,N) {
    s[i][j] = p[i] > p[j];
  }
  REP(i,K) {
    s = swapTimes(s);
  }
  double sum = 0;
  REP(i,N) FOR(j,i+1,N-1) {
    sum += s[i][j];
  }
  printf("%.15lf\n", sum);
  
  return 0;
}