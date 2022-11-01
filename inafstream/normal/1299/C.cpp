#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
#define int long long
using namespace std;

int n,nxt[1000005],l,r;
int a[1000005];
struct pnt
{
	int x,y;
}b[1000005],q[1000005];
pnt operator -(pnt x,pnt y)
{
	return (pnt){x.x-y.x,x.y-y.y};
}
int crs(pnt x,pnt y)
{
	return x.x*y.y-x.y*y.x;
}

double calc(pnt x,pnt y)
{
	return 1.0*(y.y-x.y)/(y.x-x.x);
}

signed main()
{
	int i,j;
	scanf("%lld",&n);
	rep(i,n)
	{
		int x;
		scanf("%lld",&x);
		a[i]=a[i-1]+x;
		b[i]=(pnt){i,a[i]}; 
	}
	
	l=1;
	for (i=n;i>=0;i--)
	{
		if (i<n)
		{
			int tl=l,tr=r,mid;
			pnt ans=q[r];double val=calc(b[i],ans);
			while (tl<tr)
			{
				mid=(tl+tr)/2;
				
				double tmp1=calc(b[i],q[mid]);
				if (tmp1<val)
				{
					val=tmp1;
					ans=q[mid];
				}
				double tmp2=calc(b[i],q[mid+1]);
				if (tmp2<val)
				{
					val=tmp2;
					ans=q[mid+1];
				}
				
				if (tmp1<=tmp2)
				{
					tr=mid;
				}
				else
				{
					tl=mid+1;
				}
			}
			
			nxt[i]=ans.x;
		}
		
		if (i)
		{
			while (l<r&&crs(b[i]-q[r-1],q[r]-q[r-1])<=0) r--;
			q[++r]=b[i];
		}
	}
	
	i=0;
	while (i<n)
	{
		double res=calc(b[i],b[nxt[i]]);
		for (j=i+1;j<=nxt[i];j++)
		{
			printf("%.10f\n",res);
		}
		i=nxt[i];
	}
	return 0;
}