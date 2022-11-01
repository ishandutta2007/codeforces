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

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  REP(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  bool ans = false;
  REP(i,n-1){
    if(a[i]!=a[i+1]&&a[i+1]<2*a[i]){
      ans = true;
    }
  }
  if(ans){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }

  return 0;
}