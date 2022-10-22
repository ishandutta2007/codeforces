#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=998244353;

//
//(3)
//-(x)
//+(x,y)
//-(30)

//3
//""
//dp

//dp1[i][j][f]:xji(f=0x,f=1x)
//dp2[i][j][k][f]:xjyki(f=0x,y,f=1x,f=2y)
ll dp1[201][201][2],dp2[201][201][201][3];

//TLE
//O(1)

//AB
//sum1exact[i]:xiA
//sum1atleast[i]:xiB
ll sum1exact[402],sum1atleast[402];
//sum2exact[i]:xi,yjA
//sum2atleast[i]:xi,yjB
ll sum2exact[402][402],sum2atleast[402][402];
int main(){
  ll N,A,B,v[26];
  cin>>N;
  A=N/2;B=N-A;
  for(int i=0;i<26;++i)cin>>v[i];

  dp1[1][0][0]=25;
  dp1[1][1][1]=1;
  for(int i=1;i<200;++i){
    for(int j=0;j<=i;++j){
      //Last:x
      dp1[i+1][j+1][1]=dp1[i][j][0];
      //Last:
      dp1[i+1][j][0]=(dp1[i][j][0]*24+dp1[i][j][1]*25)%mod;
    }
  }
  dp2[1][0][0][0]=24;
  dp2[1][1][0][1]=1;
  dp2[1][0][1][2]=1;
  for(int i=1;i<200;++i){
    for(int j=0;j<=i;++j)for(int k=0;k<=i-j;++k){
      //Last:x
      dp2[i+1][j+1][k][1]=(dp2[i][j][k][0]+dp2[i][j][k][2])%mod;
      //Last:y
      dp2[i+1][j][k+1][2]=(dp2[i][j][k][0]+dp2[i][j][k][1])%mod;
      //Last:
      dp2[i+1][j][k][0]=(dp2[i][j][k][0]*23+dp2[i][j][k][1]*24+dp2[i][j][k][2]*24)%mod;
    }
  }

  for(int j=0;j<=A;++j)sum1exact[j]=(dp1[A][j][0]+dp1[A][j][1])%mod;
  for(int j=0;j<=B;++j)sum1atleast[j]=(dp1[B][j][0]+dp1[B][j][1])%mod;
  for(int j=B-1;j>=0;--j)(sum1atleast[j]+=sum1atleast[j+1])%=mod;

  for(int j=0;j<=A;++j)for(int k=0;k<=A-j;++k)sum2exact[j][k]=(dp2[A][j][k][0]+dp2[A][j][k][1]+dp2[A][j][k][2])%mod;
  for(int j=0;j<=B;++j)for(int k=0;k<=B-j;++k)sum2atleast[j][k]=(dp2[B][j][k][0]+dp2[B][j][k][1]+dp2[B][j][k][2])%mod;
  //y
  for(int j=0;j<=B;++j)for(int k=B-j-1;k>=0;--k)(sum2atleast[j][k]+=sum2atleast[j][k+1])%=mod;
  //x
  for(int j=B-1;j>=0;--j)for(int k=0;k<=B-j;++k)(sum2atleast[j][k]+=sum2atleast[j+1][k])%=mod;

  //26*25^(A-1)*26*25^(B-1)=26*26*25^(N-2)
  ll ans=26*26;
  for(int i=0;i<N-2;++i)(ans*=25)%=mod;

  //-(x)
  for(int xid=0;xid<26;++xid){
    int x=v[xid];
    for(int i=0;i<=x+1;++i){
      ans+=mod-sum1exact[i]*sum1atleast[x+1-i]%mod;
      ans%=mod;
    }
  }
  //+(x,y)
  for(int xid=0;xid<26;++xid)for(int yid=xid+1;yid<26;++yid){
    int x=v[xid];int y=v[yid];
    for(int i=0;i<=x+1;++i)for(int j=0;j<=y+1;++j){
      ans+=sum2exact[i][j]*sum2atleast[x+1-i][y+1-j]%mod;
      ans%=mod;
    }
  }
  cout<<ans<<"\n";
}