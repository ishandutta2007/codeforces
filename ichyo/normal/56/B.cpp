#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  cin>>n;
  vector<int> seq(n);
  vector<int> perm(n);
  REP(i,n)cin>>seq[i];
  REP(i,n)perm[i] = i+1;
  if(seq==perm) cout<<"0 0"<<endl;
  else{
    bool ans = true;
    int begin=0;
    int end = n;
    REP(i,n){
      if(seq[i]!=perm[i]){
        begin = i+1;
        end = seq[i];
        break;
      }
    }
    FOR(i,begin,end){
      if(seq[i]-seq[i-1]!=-1){
        ans = false;
      }
    }
    FOR(i,end,n){
      if(seq[i]!=perm[i]){
        ans=false;
      }
    }
    if(ans){
      cout<<begin<<" "<<end<<endl;
    }else{
      cout<<"0 0"<<endl;
    }
  }
  
  return 0;
}