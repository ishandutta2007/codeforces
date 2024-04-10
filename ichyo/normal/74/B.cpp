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

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  string s,state;
  cin>>s>>s>>state;
  int direct = (s=="tail")?1:-1;
  int T = state.size();
  int xc = k, xs = m;
  bool lose = false;
  REP(i,T){
    if(1<= xc + direct && xc + direct <= n){
      xc += direct;
    }else{
      direct *= -1;
      xc += direct;
    }
    if(state[i]=='1'){
      if(direct == 1){
        xs = 1;
      }else{
        xs = n;
      }
    }else{
      if(xs != 1 && xs < xc-direct) xs--;
      if(xs != n && xc-direct < xs) xs++;
      if(xc == xs){
        lose = true;
        printf("Controller %d\n",i+1);
        break;
      }
    }
  }
  if(!lose){
    cout<<"Stowaway"<<endl;
  }
  return 0;
}