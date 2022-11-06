#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long C[101][101],i,j,n,m,T,ans;
int main()
{
	C[0][0]=1;
	for (i=1;i<=60;i++)
	    {
	    	C[i][0]=C[i][i]=1;
	    	for (j=1;j<i;j++)
	    	   C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	n=read();m=read();T=read();
	for (i=4;i<=n;i++)
	    if (T-i>=1)
	        ans=ans+C[n][i]*C[m][T-i];
	printf("%lld\n",ans);
	return 0;
}