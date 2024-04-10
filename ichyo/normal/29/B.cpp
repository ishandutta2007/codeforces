#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
using namespace std;
typedef long long LL;
static const double EPS = 1e-7;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n) 

int main(void){
  double l,d,v,g,r;
  cin>>l>>d>>v>>g>>r;
  double syuki = g + r;
  double sigt = d/v;
  double ans = l/v;
  double ama = sigt-syuki*(int)(sigt/syuki);
  if(ama+EPS>=g)
    ans += syuki - ama;
  printf("%.6f\n",ans);
  return 0;
}