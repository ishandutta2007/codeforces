#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e6+10;
int k,all,q,dp[maxn],mp[maxn],ano[maxn];char A[maxn],S[maxn];

int main(){
  scanf("%d%s%d",&k,A+1,&q);
  all=(1<<k)-1;
  int cur=1<<(k-1),tp=1;
  per(i,k-1,0){
    rep(j,1,1<<i)mp[cur++]=tp++;
    if(i!=iend)cur=(1<<(i-1));
  }
  rep(i,1,all)ano[mp[i]]=i;
//  memcpy(mp,ano,sizeof mp);
//  rep(i,1,all)printf("%d%c",mp[i],"\n "[i<iend]);
  rep(i,1,all)S[i]=A[mp[i]];
  rep(i,1,(1<<k))dp[all+i]=1;
  per(i,all,1){
    if(S[i]=='0'){
      dp[i]=dp[i<<1];
    }else if(S[i]=='1'){
      dp[i]=dp[i<<1|1];
    }else{
      dp[i]=dp[i<<1]+dp[i<<1|1];
    }
  }
  while(q--){
    int i;char str[5];
    scanf("%d%s",&i,str);
    i=ano[i];
    S[i]=*str;
    while(i){
      if(S[i]=='0'){
        dp[i]=dp[i<<1];
      }else if(S[i]=='1'){
        dp[i]=dp[i<<1|1];
      }else{
        dp[i]=dp[i<<1]+dp[i<<1|1];
      }
      i/=2;
    }
//    rep(i,1,all)printf("%d : %d\n",i,dp[i]);
    printf("%d\n",dp[1]);
  }
  return 0;
}