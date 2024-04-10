#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e6;
int q,t[maxn+100][10],dp[maxn+100];

int f(int x)
{
  int tmp=1;
  while(x)
    {
      if(x%10) tmp*=x%10;
      x/=10;
    }
  return tmp;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>q;
  for(int i=1;i<10;i++){
    dp[i]=i;
    for(int j=1;j<=i;j++)
      t[i][j]=1;
  }
  for(int i=10;i<=maxn;i++)
    {
      for(int j=1;j<10;j++)
	t[i][j]=t[i-1][j];
      dp[i]=dp[f(i)];
      t[i][dp[i]]++;
    }
  for(int i=0;i<q;i++)
    {
      int l,r,k;
      cin>>l>>r>>k;
      cout<<t[r][k]-t[l-1][k]<<endl;
    }
}