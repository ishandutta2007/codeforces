#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

const long double pi=acos(-1);
long long ans;
long long n,m,i,j,c;
struct pnt
{
	long long x,y;
	long double ag;
}a[2505],b[2505];
long long lim[2505];
bool cmp(pnt x,pnt y)
{
	return 1ll*x.x*y.y-1ll*x.y*y.x<0;
}
bool cmp2(pnt x,pnt y)
{
	return x.ag>y.ag;
}

void solve(long long x)
{
	long long i,j;c=0;
	rep(i,n) if (i!=x)
	{
		b[++c]=(pnt){a[i].x-a[x].x,a[i].y-a[x].y,0};
		b[c].ag=atan2(b[c].y,b[c].x);
	}
	
	sort(b+1,b+c+1,cmp2);
	rep(i,c)
	{
		if (!cmp(b[i],b[i%c+1]))
		{
			lim[i]=i;
			continue;
		}
		if (i==1) lim[i]=1; else lim[i]=lim[i-1];
		if (lim[i]==i-1&&!cmp(b[i],b[lim[i]])) lim[i]=i;
		while (cmp(b[i],b[lim[i]%c+1])) lim[i]=lim[i]%c+1;
	}
	
	ans+=1ll*c*(c-1)*(c-2)*(c-3)/24;
	rep(i,c)
	{
		long long t=lim[i]-i;if (t<0) t+=c;
		ans-=1ll*t*(t-1)*(t-2)/6;
	}
}

int main()
{
//	cerr<<atan2(0,-1)<<endl;
	scanf("%lld",&n);
	rep(i,n)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	
	rep(i,n)
	{
		solve(i);
	}
	
//	cerr<<ans<<endl;
	cout<<ans<<endl;
	return 0;
}