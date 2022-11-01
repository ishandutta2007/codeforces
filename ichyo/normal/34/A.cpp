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
  int n;
  cin>>n;
  REP(i,n){
    cin>>a[i];
  }
  int min = abs(a[1]-a[0]);
  int ans = 0;
  FOR(i,1,n){
    if(abs(a[(i+1)%n] - a[i])<min){
      min = abs(a[(i+1)%n] - a[i]);
      ans = i;
    }
  }
  printf("%d %d\n",ans+1,(ans+1)%n+1);
  return 0;
}