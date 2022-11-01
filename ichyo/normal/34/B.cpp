#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
int a[100];
int main(void){
  int n,m;
  cin>>n>>m;
  REP(i,n){
    cin>>a[i];
  }
  sort(a, a+n);
  int sum = 0;
  REP(i,m){
    if(a[i]<0){
      sum+=(-a[i]);
    }else{
      break;
    }
  }
  printf("%d\n",sum);
  return 0;
}