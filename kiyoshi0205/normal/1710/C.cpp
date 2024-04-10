#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<static_cast<int>(N);++i)
struct mint{
  int val;
  mint(int x=0):val(x){}
  void operator +=(mint y){
    val+=y.val;
    if(val>=998244353)val-=998244353;
  }
  operator bool(){return val!=0;}
  friend ostream& operator <<(ostream& os,mint x){return os<<x.val;}
};
mint dp[2][2][8][4][4];
int main(){
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin>>s;
  dp[0][0][7][3][3]=1;
  for(auto c:s){
    int x=c&1;
    rep(phase,2)rep(indexbit,8)rep(firstsoloid,4)rep(secondsoloid,4)dp[1][phase][indexbit][firstsoloid][secondsoloid]=0;
    rep(phase,2)rep(indexbit,8)rep(firstsoloid,4)rep(secondsoloid,4)if(dp[0][phase][indexbit][firstsoloid][secondsoloid]){
      rep(nxtvaluebit,8){
        int nxtphase=phase,nxtindexbit=indexbit,nxtfirstsoloid=firstsoloid,nxtsecondsoloid=secondsoloid;

        // N
        if(x==1)nxtindexbit&=nxtvaluebit;
        else if(indexbit&nxtvaluebit)continue;

        if(phase==0){
          // firstsoloid
          if(firstsoloid!=3){
            if(nxtvaluebit!=(1<<firstsoloid)&&nxtvaluebit!=(7^(1<<firstsoloid))){
              rep(i,3)if((nxtvaluebit>>firstsoloid&1)^(nxtvaluebit>>i&1)){
                nxtphase=1;
                nxtsecondsoloid=i;
              }
            }
          }else{
            rep(i,3)if(nxtvaluebit==(1<<i)||nxtvaluebit==(7^(1<<i)))nxtfirstsoloid=i;
          }
        }else if(secondsoloid!=3){
          // firstsoloid->secondsoloid
          // 
          const int remid=firstsoloid^secondsoloid^3;
          if(nxtvaluebit==(1<<remid)||nxtvaluebit==(7^(1<<remid)))nxtsecondsoloid=3;
        }
        dp[1][nxtphase][nxtindexbit][nxtfirstsoloid][nxtsecondsoloid]+=dp[0][phase][indexbit][firstsoloid][secondsoloid];
      }
    }
    swap(dp[0],dp[1]);
  }
  mint ans=0;
  rep(bit,8)rep(firstsoloid,3)ans+=dp[0][1][bit][firstsoloid][3];
  cout<<ans<<"\n";
}