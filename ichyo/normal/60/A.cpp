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

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
bool no[10000];
int main(void){
  int n,m;
  cin>>n>>m;
  memset(no,0,sizeof(no));
  while(m--){
    string ss;
    string tmp;
    int num;
    cin>>ss>>ss>>ss>>tmp>>num;
    if(ss=="right"){
      for(int i=num;i>0;i--){
        no[i] = true;
      }
    }else{
      for(int i=num;i<=n;i++){
        no[i] = true;
      }
    }
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
    if(no[i]==false) ans++;
  }
  if(ans==0) ans = -1;
  cout<<ans<<endl;
  return 0;
}