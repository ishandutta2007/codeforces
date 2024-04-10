#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

struct Point
{
	LL x,y,z;
}p[MAXN];

int n;

bool check(LL x)
{
	LL d[4][2];
	for (int i=0;i<4;i++)
	{
		d[i][0]=LLONG_MAX;
		d[i][1]=LLONG_MIN;
	}
	for (int i=0;i<n;i++)
	{
		d[0][0]=min(d[0][0],-p[i].x+p[i].y+p[i].z+x);
		d[0][1]=max(d[0][1],-p[i].x+p[i].y+p[i].z-x);
		d[1][0]=min(d[1][0],p[i].x-p[i].y+p[i].z+x);
		d[1][1]=max(d[1][1],p[i].x-p[i].y+p[i].z-x);
		d[2][0]=min(d[2][0],p[i].x+p[i].y-p[i].z+x);
		d[2][1]=max(d[2][1],p[i].x+p[i].y-p[i].z-x);
		d[3][0]=min(d[3][0],p[i].x+p[i].y+p[i].z+x);
		d[3][1]=max(d[3][1],p[i].x+p[i].y+p[i].z-x);
	}
	bool flag=true;
	LL t[4][2];
	for (int i=0;i<4;i++)
	{
		t[i][0]=d[i][0]-(d[i][0]%2?1:0);
		t[i][1]=d[i][1]+(d[i][1]%2?1:0);
		if (t[i][0]<t[i][1])
		{
			flag=false;
			break;
		}
	}
	if (flag&&t[0][0]+t[1][0]+t[2][0]>=t[3][1]&&t[0][1]+t[1][1]+t[2][1]<=t[3][0]) return true;
	flag=true;
	for (int i=0;i<4;i++)
	{
		t[i][0]=d[i][0]-(d[i][0]%2?0:1);
		t[i][1]=d[i][1]+(d[i][1]%2?0:1);
		if (t[i][0]<t[i][1])
		{
			flag=false;
			break;
		}
	}
	if (flag&&t[0][0]+t[1][0]+t[2][0]>=t[3][1]&&t[0][1]+t[1][1]+t[2][1]<=t[3][0]) return true;
	return false;
}

inline void getans(LL t[4][2])
{
	LL a[3],now=0;
	for (int i=0;i<3;i++)
	{
		a[i]=t[i][0];
		now+=a[i];
	}
	if (now>t[3][0])
		for (int i=0;;i++)
			if (now-t[i][0]+t[i][1]>t[3][0])
			{
				now-=t[i][0]-t[i][1];
				a[i]=t[i][1];
			}
			else
			{
				a[i]-=now-t[3][0];
				break;
			}
	printf("%lld %lld %lld\n",a[1]+a[2]>>1,a[0]+a[2]>>1,a[0]+a[1]>>1);
}

void solve()
{
	scanf("%d",&n);
	LL l=0,r=0;
	for (int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].z);
		r=max(r,abs(p[i].x)+abs(p[i].y)+abs(p[i].z));
	}
	while (l<=r)
	{
		LL m=l+r>>1;
		if (check(m)) r=m-1;
		else l=m+1;
	}
	LL d[4][2];
	for (int i=0;i<4;i++)
	{
		d[i][0]=LLONG_MAX;
		d[i][1]=LLONG_MIN;
	}
	for (int i=0;i<n;i++)
	{
		d[0][0]=min(d[0][0],-p[i].x+p[i].y+p[i].z+l);
		d[0][1]=max(d[0][1],-p[i].x+p[i].y+p[i].z-l);
		d[1][0]=min(d[1][0],p[i].x-p[i].y+p[i].z+l);
		d[1][1]=max(d[1][1],p[i].x-p[i].y+p[i].z-l);
		d[2][0]=min(d[2][0],p[i].x+p[i].y-p[i].z+l);
		d[2][1]=max(d[2][1],p[i].x+p[i].y-p[i].z-l);
		d[3][0]=min(d[3][0],p[i].x+p[i].y+p[i].z+l);
		d[3][1]=max(d[3][1],p[i].x+p[i].y+p[i].z-l);
	}
	bool flag=true;
	LL t[4][2];
	for (int i=0;i<4;i++)
	{
		t[i][0]=d[i][0]-(d[i][0]%2?1:0);
		t[i][1]=d[i][1]+(d[i][1]%2?1:0);
		if (t[i][0]<t[i][1])
		{
			flag=false;
			break;
		}
	}
	if (flag&&t[0][0]+t[1][0]+t[2][0]>=t[3][1]&&t[0][1]+t[1][1]+t[2][1]<=t[3][0])
	{
		getans(t);
		return;
	}
	for (int i=0;i<4;i++)
	{
		t[i][0]=d[i][0]-(d[i][0]%2?0:1);
		t[i][1]=d[i][1]+(d[i][1]%2?0:1);
	}
	getans(t);
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}