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
typedef pair<int,int> P;
int n;
vector<int> vx;
vector<int> vy;
vector<int> vr;
bool ok(int x,int y){
  REP(i,n){
    int difx = abs(x-vx[i]);
    int dify = abs(y-vy[i]);
    if(difx*difx+dify*dify<=vr[i]*vr[i]){
      return false;
    }
  }
  return true;
}
int main(){
  int xa,ya,xb,yb;
  cin>>xa>>ya>>xb>>yb;
  cin>>n;
  vx = vector<int>(n);
  vy = vector<int>(n);
  vr = vector<int>(n);
  REP(i,n){
    cin>>vx[i]>>vy[i]>>vr[i];
  }
  int ans = 0;
  for(int y = min(ya,yb); y <= max(ya,yb); y++){
    if(ok(xa,y)){
      ans++;
    }
    if(ok(xb,y)){
      ans++;
    }
  }
  for(int x = min(xa,xb)+1; x <= max(xa,xb)-1; x++){
    if(ok(x,ya)){
      ans++;
    }
    if(ok(x,yb)){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}