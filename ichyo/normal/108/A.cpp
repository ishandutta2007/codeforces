#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
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
int rev(int n){
  return (n/10)+10*(n%10);
}
int main(){
  int time,h,m;
  scanf("%d:%d",&h,&m);
  time = 60*h+m;
  while(true){
    time = (time+1)%(24*60);
    h = time/60;
    m = time%60;
    if(rev(h)==m){
      printf("%02d:%02d\n",h,m);
      break;
    }
  }
  return 0;
}