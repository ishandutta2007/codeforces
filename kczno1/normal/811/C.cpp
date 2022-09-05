#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
int cnt[N],a[N],f[N];bool vis[N];
int need;

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i){scanf("%d",a+i);++cnt[a[i]];}
	for(i=1;i<=n;++i)
	{
		need=0;int s=0;
		memset(vis,0,sizeof(vis));
		for(j=i;j;)
		{
			if(!vis[a[j]]) { vis[a[j]]=1;need+=cnt[a[j]];s^=a[j]; }
			--j;
			f[i]=max(f[i],f[j]+(--need?0:s));
		}
	}
	printf("%d\n",f[n]);
}