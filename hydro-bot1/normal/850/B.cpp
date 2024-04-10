// Hydro submission #6277b72c100a2135bc381de2@1652012845047
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],cnt[2000010],sum[2000010];
signed main()
{
	int n,x,y,maxn=0,ans=0x7fffffffffffffff;scanf("%lld%lld%lld",&n,&x,&y); 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++,sum[a[i]]+=a[i],maxn=max(maxn,a[i]);
	if(maxn==1) return printf("%lld",n*min(x,y)),0;
	for(int i=2;i<=maxn*2;i++) cnt[i]+=cnt[i-1],sum[i]+=sum[i-1];
	for(int i=2;i<=maxn;i++)
	{
		int s=0;
		for(int j=i;j<=maxn+i;j+=i)
		{
			int r=j,l=r-i+1,upd=r-(long long)(ceil((double)x/(double)y)+0.5);
			if(upd>=l) s+=x*(cnt[upd]-cnt[l-1]);
			else upd=l-1;
			s+=y*((cnt[r]-cnt[upd])*r-(sum[r]-sum[upd]));
		}
		ans=min(ans,s);
	}
	printf("%lld",ans);return 0;
}