#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 1005
int t,n,m,i,j,k,ans,a[MAXN][MAXN],h[MAXN],ne[MAXN],p[MAXN],in[MAXN],he,ta,q[MAXN];
bool b[MAXN][MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			fill(a[i],a[i]+n,-1);
			fill(b[i],b[i]+n,0);
			scanf("%d",a[i]);
			if(!a[i][0])a[i][0]=-1;
			else if(a[i][0]>=P)
			{
				a[i][0]-=P;
				b[i][0]=1;
			}
		}
		fill(h+1,h+n+1,0);
		fill(in+1,in+n+1,0);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&j,p+i);
			in[p[i]]++;
			ne[i]=h[j];
			h[j]=i;
		}
		he=ta=0;
		for(i=1;i<=n;i++)if(!in[i])q[ta++]=i;
		while(he!=ta)
		{
			i=q[he++];
			for(j=0,k=-1;j<n;j++)if(~a[i][j])if(!~k||!b[i][k]&&a[i][k]+k<j)k=j;
			else
			{
				a[i][k]+=a[i][j];
				b[i][k]|=b[i][j];
				if(a[i][k]>=P)
				{
					b[i][k]=1;
					a[i][k]-=P;
				}
				a[i][j]=-1;
			}
			if(h[i])for(j=h[i];j;j=ne[j])
			{
				for(k=0;k+1<n;k++)if(~a[i][k])if(~a[p[j]][k+1])
				{
					a[p[j]][k+1]+=a[i][k];
					b[p[j]][k+1]|=b[i][k];
					if(a[p[j]][k+1]>=P)
					{
						a[p[j]][k+1]-=P;
						b[p[j]][k+1]=1;
					}
				}
				else
				{
					a[p[j]][k+1]=a[i][k];
					b[p[j]][k+1]=b[i][k];
				}
				if(!--in[p[j]])q[ta++]=p[j];
			}
			else
			{
				for(j=n-1;~j&&!~a[i][j];j--);
				if(~j)ans=(a[i][j]+j)%P;
				else ans=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}