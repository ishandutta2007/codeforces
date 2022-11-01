#include <bits/stdc++.h>
using namespace std;

const int INF=10000000;


int main()
{
  int n,K,m;
  scanf("%d%d%d",&n,&K,&m);
  vector<int> e[100],c[100];
  for(int i=0;i<m;i++){
    int u,v,ct;
    scanf("%d%d%d",&u,&v,&ct);
    u--,v--;
    e[u].push_back(v);
    c[u].push_back(ct);
  }
  static int dp[81][81][82];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dp[i][j][0]=0;
      for(int k=1;k<=K;k++){
	dp[i][j][k]=INF;
      }
    }
  }
  for(int d=0;d<n;d++){
    for(int b=0;b<2;b++){
      for(int i=0;i<n;i++){
	int j=i+(b?d:-d);
	if(0>j||n<=j){
	  continue;
	}
	for(int x=0;x<e[i].size();x++){
	  int p=e[i][x];
	  if(!((i<p&&p<=j)||(i>p&&p>=j))){
	    continue;
	  }
	  for(int k=1;k<=K;k++){
	    dp[i][j][k]=min(dp[i][j][k],dp[p][i<p?i+1:i-1][k-1]+c[i][x]);
	    dp[i][j][k]=min(dp[i][j][k],dp[p][j][k-1]+c[i][x]);
	  }
	}
	/*for(int k=0;k<=K;k++){
	  printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
	  }*/
      }
    }
  }
  int ans=INF;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ans=min(ans,dp[i][j][K-1]);
    }
  }
  printf("%d\n",ans<INF?ans:-1);
  return 0;
}