#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
int n,ans,i,j,k,a[3005],b[3005],lcp[3005][3005],f[3005][3005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]==a[j])lcp[i][j]=lcp[i-1][j-1]+1;
	for(i=4;i<=n;i++)for(j=i-3;j<=i;j++)b[i]=b[i]<<1|a[j];
	for(i=1;i<=n;i++)for(f[i][i-1]=1,j=i;j<=n;j++)
	{
		for(k=1;k<4&&k+i<j+2;k++)f[i][j]=(f[i][j]+f[i][j-k])%P;
		if(i+2<j&&b[j]!=3&&b[j]!=5&&b[j]!=14&&b[j]!=15)f[i][j]=(f[i][j]+f[i][j-4])%P;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1,k=0;j<i;j++)k=max(k,lcp[i][j]);
		for(k++;k<=i;k++)ans=(ans+f[i-k+1][i])%P;
		cout<<ans<<endl;
	}
	return 0;
}