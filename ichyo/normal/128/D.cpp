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
#define FOREQ(i,k,n) for(int i=(k); i<=(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
bool solve(vector<int>& a){
  int n = a.size();
  sort(a.begin(),a.end());
  REP(i,n-1)if(a[i+1]-a[i]>1) return false;
  int c[100001]={};
  REP(i,n)c[a[i]-a.front()]++;
  int maxn = a.back()-a.front();
  FOREQ(i,0,maxn){
    if(i==0||i==maxn){
      c[i]--;
      n--;
    }else if(c[i]>=2){
      c[i]-=2;
      n-=2;
    }else{
      return false;
    }
  }
  FOREQ(i,0,maxn-1){
    int m = c[i];
    c[i+1] -= m;
  }
TURNEND:;
  return c[maxn]==0;
}

int main(){
  int n;
  while(cin>>n){
    vector<int> a(n);
    REP(i,n)cin>>a[i];
    if(solve(a)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

  return 0;
}