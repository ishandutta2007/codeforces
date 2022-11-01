#include <bits/stdc++.h>
using namespace std;

const long long INF=100000000000000000ll;

int main()
{
  int n,m,W;
  scanf("%d%d%d",&n,&m,&W);
  vector<vector<int> > e(n);
  int w[1000];
  long long b[1000];
  for(int i=0;i<n;i++){
    scanf("%d",w+i);
  }
  for(int i=0;i<n;i++){
    scanf("%I64d",b+i);
  }
  for(int i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  bool B[1000]={0};
  long long dp[2][1010];
  bool f=0;
  dp[f][0]=0;
  for(int i=1;i<=W;i++){
    dp[f][i]=-INF;
  }
  for(int i=0;i<n;i++){
    if(B[i]){
      continue;
    }
    for(int x=0;x<=W;x++){
      dp[!f][x]=dp[f][x];
    }
    B[i]=1;
    queue<int> Q;
    Q.push(i);
    int Tw=0;
    long long Tb=0ll;
    while(!Q.empty()){
      int j=Q.front();
      Tw+=w[j];
      Tb+=b[j];
      for(int x=w[j];x<=W;x++){
	dp[!f][x]=max(dp[!f][x],dp[f][x-w[j]]+b[j]);
      }
      Q.pop();
      for(int x=0;x<e[j].size();x++){
	int k=e[j][x];
	if(!B[k]){
	  B[k]=1;
	  Q.push(k);
	}
      }
    }
    for(int x=Tw;x<=W;x++){
      dp[!f][x]=max(dp[!f][x],dp[f][x-Tw]+Tb);
    }
    f=!f;
  }
  long long ans=0ll;
  for(int x=0;x<=W;x++){
    ans=max(ans,dp[f][x]);
  }
  printf("%I64d\n",ans);
  return 0;
}