#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
long long n,m,i,j,k,l,p,x,cnt[75];
int mp[75][75],dis[75][75],tmp[75][75],ans;

void rebuild()
{
	int i,j,k;
	for (i=0;i<=63;i++)
	{
		for (j=0;j<=63;j++)
		{
			dis[i][j]=(mp[i][j]?1:inf);
		}
		dis[i][i]=0;
	}
	for (k=0;k<=63;k++)for (i=0;i<=63;i++)for (j=0;j<=63;j++)
	{
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
}

int main()
{
	ans=inf;
	for (i=0;i<=63;i++)
	{
		for (j=0;j<=63;j++)
		{
			mp[i][j]=0;
		}
		dis[i][i]=0;
	}
	
	scanf("%I64d",&n);
	rebuild();
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
//		memcpy(tmp,dis,sizeof(tmp));
		bool f=0;
		for (j=0;j<=63;j++) if (((x>>j)&1))
		{
			cnt[j]++;
			if (cnt[j]>=3) ans=min(ans,3);
			for (k=0;k<=63;k++) if (j!=k&&((x>>k)&1))
			{
				if(!mp[j][k])
				{
					ans=min(ans,1+dis[j][k]);
					mp[j][k]=1;
					f=1;
				}
			}
		}
		if(f) rebuild();
	}
	
	if(ans==inf)cout<<-1<<endl;else cout<<ans<<endl;
	return 0;
}