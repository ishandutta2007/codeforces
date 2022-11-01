#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

const long long gg=3e16;
long long x,y,xs,ys;
long long ax,ay,bx,by,t;
vector<long long> vx,vy;
int ans;

long long dis(long long x1,long long y1,long long x2,long long y2)
{
	return abs(x1-x2)+abs(y1-y2);
}

bool check(int l,int r)
{
	long long rem=t;
	int i;
	
	if (l<r)
	{
		if (dis(xs,ys,vx[l],vy[l])>rem) return 0;
		rem-=dis(xs,ys,vx[l],vy[l]);
		for (i=l+1;i<=r;i++)
		{
			if (dis(vx[i-1],vy[i-1],vx[i],vy[i])>rem) return 0;
			rem-=dis(vx[i-1],vy[i-1],vx[i],vy[i]);
		}
		return 1;
	}
	else
	{
		swap(l,r);
		if (dis(xs,ys,vx[r],vy[r])>rem) return 0;
		rem-=dis(xs,ys,vx[r],vy[r]);
		for (i=l+1;i<=r;i++)
		{
			if (dis(vx[i-1],vy[i-1],vx[i],vy[i])>rem) return 0;
			rem-=dis(vx[i-1],vy[i-1],vx[i],vy[i]);
		}
		return 1;
	}
}

int main()
{
	cin>>x>>y>>ax>>ay>>bx>>by;
	cin>>xs>>ys>>t;
	
	vx.push_back(x);
	vy.push_back(y);
	while (1)
	{
		if (x>gg||y>gg) break;
		x=ax*x+bx;
		y=ay*y+by;
		vx.push_back(x);
		vy.push_back(y);
	}
	
	int i,j;
	for (i=0;i<vx.size();i++)
	{
		for (j=i;j<vx.size();j++)
		{
			if (check(i,j)) ans=max(ans,j-i+1);
			if (check(j,i)) ans=max(ans,j-i+1);
		}
	}
	
	printf("%d\n",ans);
	return 0;
}