#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
int m,k,i,j,n[1005],a[1005],b[1005],d[1005],f[1005][1005],ans;
char c[1005];
int main()
{
	scanf("%s%d",c,&k);
	m=strlen(c);
	for(i=0;i<m;i++)n[i+1]=c[i]^'0';
	for(a[1]=1,i=2;i<=1000;i++)
	{
		a[i]=a[i>>1]+(i&1);
		b[i]=b[a[i]]+1;
	}
	f[1][0]=d[1]=1;
	for(i=2;i<=m;i++)
	{
		d[i]=d[i-1]+n[i];
		for(j=0;j<=i;j++)
		{
			f[i][j]=(f[i][j]+f[i-1][j])%P;
			f[i][j+1]=(f[i][j+1]+f[i-1][j])%P;
		}
		if(n[i])f[i][d[i-1]]=(f[i][d[i-1]]+1)%P;
	}
	f[m][d[m]]=(f[m][d[m]]+1)%P;
	f[m][1]=(f[m][1]+P-1)%P;
	for(i=1;i<=m;i++)if(b[i]+1==k)ans=(ans+f[m][i])%P;
	if(!k)ans=(ans+1)%P;
	cout<<ans<<endl;
	return 0;
}