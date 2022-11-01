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
#include <fstream>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int dfs(int now,int bk, vector<int> a[]){
  int ret = 0;
  REP(i,a[now].size()){
    if(a[now][i] != bk)
      ret = max(ret, dfs(a[now][i],now, a) + 1);
  }
  return ret;
}
int main(){
  ifstream ifs("input.txt");
  ofstream ofs("output.txt");
  int T;
  ifs>>T;
  int ans = 0;
  while(T--){
    int n;
    ifs>>n;
    vector<int> a[101];
    REP(i,n-1){
      int p,q;
      ifs>>p>>q;
      p--; q--;
      a[p].push_back(q);
      a[q].push_back(p);
    }
    int mans = 1;
    REP(i,n){
      if(a[i].size()==1){
        mans = max(mans, dfs(a[i][0],i,a)+1);
      }
    }
    ans += mans;
  }
  ofs<<ans<<endl;
  return 0;
}