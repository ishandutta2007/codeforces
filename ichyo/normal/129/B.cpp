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
  int n,m;
  cin>>n>>m;
  set<int> count[100];
  REP(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    count[a].insert(b);
    count[b].insert(a);
  }
  int ans = 0;
  while(true){
    set<int> nxcount[100];
    REP(i,n)nxcount[i] = count[i];
    bool update = false;
    REP(i,n){
      if(count[i].size() == 1){
        update = true;
        int aite = *count[i].begin();
        nxcount[i].clear();
        nxcount[aite].erase(i);
      }
    }
    if(!update) break;
    ans++;
    REP(i,n)count[i] = nxcount[i];
  }
  cout<<ans<<endl;
  return 0;
}