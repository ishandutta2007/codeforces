#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,i,j,k,l,m,o,x[50],y[50];
int main()
{
	scanf("%d",&n);
	n=n*4+1;
	for(i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(x[i]<x[j])for(k=1;k<=n;k++)for(l=1;l<=n;l++)if(y[k]<y[l]&&x[j]-x[i]==y[l]-y[k])
	{
		for(m=1,o=0;m<=n;m++)if(!(x[m]>=x[i]&&x[m]<=x[j]&&y[m]>=y[k]&&y[m]<=y[l]&&(x[m]==x[i]||x[m]==x[j]||y[m]==y[k]||y[m]==y[l])))o++;
		if(o==1)
		{
			for(m=1,o=0;m<=n;m++)if(!(x[m]>=x[i]&&x[m]<=x[j]&&y[m]>=y[k]&&y[m]<=y[l]&&(x[m]==x[i]||x[m]==x[j]||y[m]==y[k]||y[m]==y[l])))cout<<x[m]<<' '<<y[m]<<endl;
			return 0;
		}
	}
	return 0;
}