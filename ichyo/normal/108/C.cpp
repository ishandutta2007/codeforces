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
typedef long long ll;
typedef pair<int, int> P;
static const double EPS = 1e-8;
static const int INF = (1<<29);

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FIND(m,w) ((m).find(w)!=(m).end())
struct course{
  int tank,tap,amt;
  course(int tank,int tap,int amt):tank(tank),tap(tap),amt(amt){}
};
bool operator < (const course &e, const course &f){
  return e.tank < f.tank;
}
int main(void){
  int n,p;
  cin>>n>>p;
  int out[1001];
  bool in[1001]={};
  bool arv[1001]={};
  int amount[1001];
  REP(i,n){
    out[i] = -1;
  }
  REP(i,p){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    out[a] = b;
    amount[a] = c;
    in[b] = true;
  }
  vector<course> ans;
  REP(i,n){
    if(in[i]) continue;
    int minamt = amount[i];
    int next = out[i];
    if(next==-1) continue;
    bool loop = false;
    while(out[next]!=-1){
      minamt = min(minamt,amount[next]);
      arv[next] = true;
      next = out[next];
      if(arv[next]){
        loop = true;
        break;
      }
    }
    if(!loop){
      ans.push_back(course(i,next,minamt));
    }
  }
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  REP(i,ans.size()){
    printf("%d %d %d\n",ans[i].tank+1,ans[i].tap+1,ans[i].amt);
  }
  return 0;
}