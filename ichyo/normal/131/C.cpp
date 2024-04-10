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
typedef long long ll;

int main(){
  ll comb[50][50];
  REP(i,50)comb[i][0] = comb[i][i] = 1;
  FOR(i,1,50)FOR(j,1,50)comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
  int n,m,t;
  cin>>n>>m>>t;
  ll ans = 0;
  FOR(man,4,t+1){
    int woman = t - man;
    if(woman > 0 && man <= n && woman <= m){
      ans += comb[n][man] * comb[m][woman];
    }
  }
  cout<<ans<<endl;

  return 0;
}