#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int N,ma,reg,tmp1,tmp2;
  cin>>N>>ma>>reg;
  int hp = ma;
  int dmg = 0;
  vector<P> pd;
  vector<P> out;
  bool spelled[1001];
  REP(i,1001) spelled[i]=false;
  REP(i,N){
    cin>>tmp1>>tmp2;
    pd.push_back(P(tmp1,tmp2));
  }
    long long second=0;
    while(true){
      bool spelling = false;
      hp -= dmg;
      hp = min(ma,hp+reg);
      //int rate=hp*100/ma;
      int damax=-1;
      int damaxi=-1;
      if(hp<=0){
        break;
      }
      for(int i=0; i<N; i++){
        if(pd[i].first*ma>=hp*100&&spelled[i]==false){
          if(pd[i].second>damax){
            spelling = true;
            damax = pd[i].second;
            damaxi = i;
          }
        }
      }
      if(spelling){
        spelled[damaxi] = true;
        dmg+=damax;
        out.push_back(P(second,damaxi+1)); 
      }else{
        if(reg>=dmg){
          cout<<"NO"<<endl;
          break;
        }
      }
      
      second++;
    }
    if(hp<=0){
      cout<<"YES"<<endl;
      cout<<second<<" "<<out.size()<<endl;
      //printf("%d %d\n",second,(int)out.size());
      REP(i,out.size()){
        printf("%d %d\n",out[i].first,out[i].second);
      }
    }
  return 0;
}