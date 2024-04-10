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
  string s;
  while(cin>>s){
    int n = s.size();
    int a=0,b=0; 
    REP(i,n){
      if(s[i]=='4')a++;
      if(s[i]=='7')b++;
    }
    if(a==0&&b==0)cout<<-1<<endl;
    else if(a>=b) cout<<4<<endl;
    else cout<<7<<endl;
  }
    
  return 0;
}