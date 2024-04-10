#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n,m,i,j,k,l,o,x,y,ans,a[MAXN],f[2][3][5];
int main()
{
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d",&i);
		a[i]++;
	}
	memset(f,128,sizeof(f));
	f[1][0][0]=0;
	for(i=1;i<=m;i++)
	{
		memset(f[!(i&1)],128,sizeof(f[!(i&1)]));
		if(a[i]<6)
		{
			x=a[i];
			y=0;
		}
		else
		{
			y=a[i]/3-2;
			x=a[i]-y*3;
		}
		for(j=0;j<3;j++)for(k=0;k<5;k++)for(o=0;o*3<=x;o++)for(l=0;l<=j&&l<=k&&l+3*o<=x;l++)f[!(i&1)][min(k-l,2)][min(x-l-3*o,4)]=max(f[!(i&1)][min(k-l,2)][min(x-l-3*o,4)],f[i&1][j][k]+y+o+l);
	}
	for(j=0;j<3;j++)for(k=0;k<5;k++)ans=max(ans,f[m+1&1][j][k]);
	cout<<ans<<endl;
	return 0;
}