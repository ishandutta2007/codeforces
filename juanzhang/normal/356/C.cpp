#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,ct[5];

int main(){
  cin>>n;int su=0;
  rep(i,1,n){
    int x;scanf("%d",&x),ct[x]++,su+=x;
  }
  if(su<3||su==5)return puts("-1"),0;
  int res=0,dt=min(ct[1],ct[2]);
  ct[1]-=dt,ct[2]-=dt,ct[3]+=dt;
  if(!ct[1]){
    int t=ct[2]/3;
    ct[2]%=3,ct[3]+=t*2,dt+=t*2;
    if(ct[2])res=ct[2]==1&&ct[4]?1:2;
  }else if(!ct[2]){
    int t=ct[1]/3;
    ct[1]%=3,ct[3]+=t,dt+=t*2;
    if(ct[1]==1){
      res=ct[3]?1:2;
    }else if(ct[1]==2){
      res=2;
    }
  }
  cout<<res+dt<<endl;
  return 0;
}