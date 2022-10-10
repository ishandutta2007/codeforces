#include <bits/stdc++.h>

using namespace std;

short dp[1555];
short pre[1555];
int n,m;
int ar1[1555],ar2[1555];
vector <int> vans;

int main()
{
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
  {
    scanf("%d",&ar1[i]);
  }
  scanf("%d",&m);
  for (int i=1;i<=m;i++)
  {
    scanf("%d",&ar2[i]);
  }

  for (int i=1;i<=n;i++)
  {
    int len=0;
    int x=0;
    for (int j=1;j<=m;j++)
    {
      if ((ar2[j]<ar1[i])&&(dp[j]>len))
      {
        len=dp[j];
        x=j;
      }
      
      if ((ar2[j]==ar1[i])&&(len+1>dp[j]))
      {
        dp[j]=len+1;
        pre[j]=x;
      }


    }
    // for (int k=1;k<=m;k++)
    // {
    //  printf("%d ",dp[k]);
    // }
    // printf("\n");
  }

  int ans=0;
  int ians=0;

  for (int i=1;i<=m;i++)
  {
    if (dp[i]>ans)
    {
      ans=dp[i];
      ians=i;
    }
  }
  printf("%d\n",ans);
  for (int i=1;i<=ans;i++)
  {
    vans.push_back(ar2[ians]);
    ians=pre[ians];
  }

  for (int i=ans;i>0;i--)
  {
    printf("%d",vans[i-1]);
    if (i!=1)
    {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}