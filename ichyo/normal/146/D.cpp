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
  int a,b,c,d;
  while(cin>>a>>b>>c>>d){
    //printf("%d %d %d %d\n",a,b,c,d);
    if(max(c,d) > min(a,b)){
      cout<<-1<<endl;
      continue;
    }
    if(abs(c-d) > 1){
      cout<<-1<<endl;
      continue;
    }
    if(c == d){
      if(a == c && b == c){
        cout<<-1<<endl;
      }else if(a == c){
        REP(i,a)cout<<"74";
        REP(i,b-c)cout<<"7";
        cout<<endl;
      }else{
        REP(i,a-c-1)cout<<"4";
        REP(i,c)cout<<"47";
        REP(i,b-c)cout<<"7";
        cout<<"4"<<endl;
      }
    }else if(c > d){
      REP(i,a-c)cout<<"4";
      REP(i,c)cout<<"47";
      REP(i,b-c)cout<<"7";
      cout<<endl;
    }else if(c < d){
      cout<<"74";
      REP(i,a-d)cout<<"4";
      REP(i,d-2)cout<<"74";
      REP(i,b-d)cout<<"7";
      cout<<"74"<<endl;
    }
  }
  return 0;
}