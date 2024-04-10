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
  int n,k;
  cin>>n>>k;
  vector<string> nums(n);
  REP(i,n)cin>>nums[i];
  vector<int> seq(k);
  REP(i,k)seq[i] = i;
  int ans = 1e8;
  do{
    int nmax = 0;
    int nmin = 1e8;
    REP(i,n){
      int number = 0;
      REP(j,k){
        number = number * 10 + (nums[i][seq[j]]-'0');
      }
      nmax = max(nmax,number);
      nmin = min(nmin,number);
    }
    ans = min(ans,nmax-nmin);
  }while(next_permutation(seq.begin(),seq.end()));
  cout<<ans<<endl;
      

      

  return 0;
}