#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[22][1100000],n,m,t[30],a[30][30],sum,MAX,f[30];
char c[30][30];

int main()
{
  f[0]=1;
  for(int i=1;i<=21;i++)
    f[i]=f[i-1]*2;
  memset(dp,63,sizeof dp);
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=1;j<=m;j++)
      cin>>c[j][i];
  for(int i=0;i<n;i++)
    for(int j=1;j<=m;j++)
      cin>>a[j][i];
  dp[0][f[n]-1]=0;
  for(int i=1;i<=m;i++)
    {
      for(int j=0;j<26;j++)
	t[j]=0;
      for(int j=0;j<n;j++)
	t[int(c[i][j]-'a')]++;
      int x=0;
      for(int j=0;j<n;j++)
	if(t[int(c[i][j]-'a')]>1)
	  x+=f[j];
      for(int j=0;j<f[n];j++)
	dp[i][j&x]=min(dp[i][j&x],dp[i-1][j]);
      for(int j=f[n]-1;j>-1;j--)
	{
	  for(int k=0;k<n;k++)
	    if(f[k]&j)
	      dp[i][j-f[k]]=min(dp[i][j-f[k]],dp[i][j]+a[i][k]);
	}
      for(int j=0;j<26;j++)
	if(t[j]>1)
	  {
	    sum=MAX=0;
	    x=0;
	    for(int k=0;k<n;k++)
	      if(int(c[i][k]-'a')==j)
		sum+=a[i][k],MAX=max(MAX,a[i][k]),x+=f[k];
	    sum-=MAX;
	    x=f[n]-x-1;
	    // cout<<x<<" "<<sum<<endl;
	    for(int k=f[n]-1;k>-1;k--)
	      dp[i][k&x]=min(dp[i][k&x],dp[i][k]+sum);
	  }
    }
  cout<<dp[m][0]<<endl;
}