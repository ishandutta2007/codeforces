#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=500005,M=998244353;
int t,i,j,n,a[N],x[N],y[N],s[N],ansx,ansy,k,p,l,r,ans[N],dx,dy;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;)
	{
		for(j=i;a[i]==a[j];++j);
		x[++k]=j-i;
		y[k]=a[i];
		i=j;
	}
	for(i=1;i<=k;++i)
		--s[x[i]];
	p=k;
	for(i=1;i<=n;++i)
	{
		ans[i]=ans[i-1]+p;
		p+=s[i];
	}
	for(i=1;i<=n;++i)
	{
		l=1,r=i+1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(ans[mid]>=1ll*mid*i)
				l=mid+1;
			else
				r=mid;
		}
		--l;
		if(l*i>ansx*ansy)
		{
			ansx=i;
			ansy=l;
		}
	}
	printf("%d\n",ansx*ansy);
	printf("%d %d\n",ansx,ansy);
	dx=1;
	dy=1;
	p=1;
	for(i=1;i<=k&&p<=ansx;++i)
		if(x[i]>=ansy)
			for(j=1;j<=ansy;++j)
			{
				ans[(dx-1)*ansy+dy]=y[i];
				++dx;
				++dy;
				if(dx>ansx)
					dx=1;
				if(dy>ansy)
				{
					dy=1;
					dx=++p;
				}
			}
	for(i=1;i<=k&&p<=ansx;++i)
		if(x[i]<ansy)
		{
			for(j=1;x[i]&&p<=ansx;++j,--x[i])
			{
				ans[(dx-1)*ansy+dy]=y[i];
				++dx;
				++dy;
				if(dx>ansx)
					dx=1;
				if(dy>ansy)
				{
					dy=1;
					dx=++p;
				}
			}
		}
	for(i=1;i<=ansx;++i)
	{
		for(j=1;j<=ansy;++j)
			printf("%d ",ans[(i-1)*ansy+j]);
		printf("\n");
	}
}