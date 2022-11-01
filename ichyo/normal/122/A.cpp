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
bool lucky(int n){
  while(n){
    if(n%10!=4&&n%10!=7)return false;
    n/=10;
  }
  return true;
}
int main(){
  int n;
  while(cin>>n){
    for(int i = 2; i<=n; i++){
      if(lucky(i)&&n%i==0){cout<<"YES"<<endl;goto END;}
    }
    cout<<"NO"<<endl;
END:;
  }

  return 0;
}