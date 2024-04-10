#include <bits/stdc++.h>
using namespace std;
const long long INF=1000000000000000ll;

int n;
vector<int> e[5000];
vector<long long> dp1[5010],dp2[5010];
long long D[5000],C[5000];

vector<long long> mg2(vector<long long> &v1,vector<long long> &v2)
{
  int n1=v1.size(),n2=v2.size();
  vector<long long> v3=vector<long long>(n1+n2,INF);
  for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
      v3[i+j]=min(v3[i+j],v1[i]+v2[j]);
    }
  }
  return v3;
}

vector<long long> mg1(vector<long long> &v1,vector<long long> &v2,vector<long long> &v22)
{
  int n1=v1.size(),n2=v2.size();
  vector<long long> v3=vector<long long>(n1+n2,INF);
  for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
      v3[i+j]=min(v3[i+j],v1[i]+min(v2[j],v22[j]));
    }
  }
  return v3;
}


void dfs(int i)
{
  int T=1;
  dp1[i]=vector<long long>(2);
  dp1[i][0]=INF,dp1[i][1]=C[i]-D[i];
  dp2[i]=vector<long long>(2);
  dp2[i][0]=0,dp2[i][1]=C[i];
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    dfs(j);
    dp1[i]=mg1(dp1[i],dp1[j],dp2[j]);
    dp2[i]=mg2(dp2[i],dp2[j]);
  }
  /*for(int x=0;x<dp1[i].size();x++){
    printf("%d %d %lld %lld\n",i,x,dp1[i][x],dp2[i][x]);
    }*/
}

int main()
{
  long long B;
  scanf("%d%lld",&n,&B);
  int x[5000];
  for(int i=0;i<n;i++){
    scanf("%lld%lld",C+i,D+i);
    if(i>0){
      scanf("%d",x+i);
      x[i]--;
    }
  }
  for(int i=1;i<n;i++){
    e[x[i]].push_back(i);
  }
  dfs(0);
  int ans=0;
  for(int i=0;i<=n;i++){
    if(min(dp1[0][i],dp2[0][i])<=B){
      ans=i;
    }
  }
  printf("%d\n",ans);
  return 0;
}