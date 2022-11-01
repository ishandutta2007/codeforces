#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;
static const int INF = 1e8;
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int time[101];
  int money[101]={};
  int n,m;
  cin>>n>>m;
  REP(i,n) time[i] = INF;
  REP(i,m){
    int l,r,t,c;
    cin>>l>>r>>t>>c;
    l--; r--;
    for(int j=l; j<=r; j++){
      if(time[j]>t){
        time[j] = t;
        money[j] = c;
      }
    }
  }
  int ans = 0;
  REP(i,n){
    ans += money[i];
  }
  cout<<ans<<endl;
  return 0;
}