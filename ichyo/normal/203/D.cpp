#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  int a, b, m, vx, vy, vz;
  while(cin>>a>>b>>m>>vx>>vy>>vz){
    vy = abs(vy);
    double t = (double)m/vy;
    double tmpz = vz * t;
    tmpz = (tmpz/(2.0*b) - (int)(tmpz/(2.0*b))) * 2.0 * b;
    if(tmpz > b) tmpz = 2.0 * b - tmpz;
    double tmpx;
    if(vx > 0){
      tmpx = vx * t  + 0.5*a;
      tmpx = (tmpx/(2.0*a) - (int)(tmpx/(2.0*a))) * 2.0 * a;
      if(tmpx > a) tmpx = 2.0 * a - tmpx;
    }else{
      vx = abs(vx);
      tmpx = vx * t + 0.5 * a;
      tmpx = (tmpx/(2.0*a) - (int)(tmpx/(2.0*a))) * 2.0 * a;
      if(tmpx > a) tmpx = 2.0 * a - tmpx;
      tmpx = a - tmpx;
    }
    printf("%f %f\n", tmpx, tmpz);
  }
  return 0;
}