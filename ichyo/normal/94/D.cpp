#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int,double> P;
static const double EPS = 1e-8;
static const int INF = (int)1e8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FIND(m,w) ((m).find(w)!=(m).end())
int main(void){
  int n,w,m;
  cin>>n>>w>>m;
  vector<P> ans[m];
  if(0){
    REP(i,n){
      REP(j,m){
        ans[j].push_back(P(i+1,(double)w/m));
      }
    }
    cout<<"YES"<<endl;
    REP(i,m){
      REP(j,ans[i].size()){
        if(j)cout<<" ";
        printf("%d %.6lf",ans[i][j].first,ans[i][j].second);
      }
      cout<<endl;
    }
  }else if(2*n < m){
    cout<<"NO"<<endl;
  }else if(1){
    int data[100]={};
    int idx=0;
    bool able = true;
    REP(i,n){
      if(idx>=m){
        able = false;
        break;
      }
      int water = m;
      while(data[idx]==n)idx++;
      if(water-(n-data[idx])>=0){
        ans[idx].push_back(P(i+1,(double)(n-data[idx])/m*w));
        water -= (n-data[idx]);
        data[idx] = n;
        idx++;
      }else{
        ans[idx].push_back(P(i+1,w));
        water = 0;
        data[idx] += m;
      }
      if(idx>=m&&water){
        able=false;
        break;
      }
      if(water){
        ans[idx].push_back(P(i+1,(double)(water)/m*w));
        data[idx] += water;
        if(data[idx]>n){
          able = false;
          break;
        }
      }
    }
    if(able){
      cout<<"YES"<<endl;
      REP(i,m){
        REP(j,ans[i].size()){
          if(j)cout<<" ";
          printf("%d %.6lf",ans[i][j].first,ans[i][j].second);
        }
        cout<<endl;
      }
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}