#include <bits/stdc++.h>
using namespace std;

const int INF=100000;


int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  if(m==n*(n-1)/2){
    printf("%d\n",0);
    return 0;
  }
  int b[23][23]={0};
  for(int t=0;t<m;t++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    b[u][v]=b[v][u]=1;
  }
  int ms[23];
  for(int i=0;i<n;i++){
    ms[i]=0;
    for(int j=0;j<n;j++){
      ms[i]|=(b[i][j]<<j);
    }
  }
  int ans=INF;
  vector<int> ret;
  for(int s=0;s<n;s++){
    static int dp[1<<22],bk[1<<22],tk[1<<22];
    for(int I=0;I<1<<n;I++){
      dp[I]=INF;
    }
    dp[ms[s]|(1<<s)]=0;
    for(int I=0;I<1<<n;I++){
      if(dp[I]==INF)continue;
      for(int j=0;j<n;j++){
	if(!((I>>j)&1))continue;
	int J=I|ms[j];
	if(dp[J]>dp[I]+1){
	  dp[J]=dp[I]+1;
	  bk[J]=I;
	  tk[J]=j;
	}
      }
    }
    if(dp[(1<<n)-1]+1<ans){
      ans=dp[(1<<n)-1]+1;
      int I=(1<<n)-1;
      ret=vector<int>(1,s);
      while(dp[I]>0){
	ret.push_back(tk[I]);
	I=bk[I];
      }
    }
  }
  printf("%d\n",ans);
  for(int t=0;t<ans;t++){
    printf("%d%c",ret[ans-t-1]+1,t==ans-1?'\n':' ');
  }
  return 0;
}