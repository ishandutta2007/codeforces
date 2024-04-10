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
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
typedef pair<int,int> P;

int main(){
  int n,m;
  while(cin>>n>>m){
    vector<int> data(n);
    vector<int> c(m+1);
    int place[201][201];
    REP(i,m){
      int T,t; cin>>T;
      c[i+1] = T;
      REP(j,T){
        cin>>t; t--;
        data[t] = i+1;
        place[i+1][j] = t;
      }
    }
    vector<P> ans;
    int need = -1;
    int rest = 0;
    REP(i,n){
      if(need == -1){
        FOR(j,i,n)if(data[j] != 0 && need == -1)need = data[j];
        if(need==-1) goto OUTPUT;
        rest = c[need];
      }
      int np = place[need][c[need]-rest];
      if(np == i){
      }else if(data[i] == 0){
        ans.push_back(P(np,i));
        swap(data[np],data[i]);
        goto N;
      }else{
        int br = -1;
        REP(j,n)if(data[j]==0 && br == -1)br = j;
        ans.push_back(P(i,br));
        swap(data[i],data[br]);
        ans.push_back(P(np,i));
        swap(data[np],data[i]);
        REP(j,201)if(place[data[br]][j]==i) place[data[br]][j]=br;
        goto N;
      }
      N:
      /*
      cout<<i<<":"<<"need:"<<need<<":";
      debug(data.begin(), data.end());
      */
      rest--;
      if(rest == 0) need = -1;
    }
OUTPUT:
    assert(ans.size() <= 2 * n);
    cout<<ans.size()<<endl;
    REP(i,ans.size()){
      printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    }
  }
  return 0;
}