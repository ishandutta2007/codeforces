#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,l,a[N],b[N],c[N],p[N],t,i,s,k;
double ul,r;
bool check(double m)
{
	double s1=0,s2=0;
	double tm=m;
	for(i=1;i<=n+1;++i)
	{
		if(((double)(a[i]-a[i-1]))/i<=tm)
			tm-=((double)(a[i]-a[i-1]))/i;
		else
		{
			s1+=i*tm;
			break;
		}
		s1=a[i];
	}
	s2=l;
	tm=m;
	for(i=n;i>=0;--i)
	{
		if(((double)(a[i+1]-a[i]))/(n-i+1)<=tm)
			tm-=((double)(a[i+1]-a[i]))/(n-i+1);
		else
		{
			s2-=(n-i+1)*tm;
			break;
		}
		s2=a[i];
	}
	return s1>=s2;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&l);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		a[n+1]=l;
		ul=0,r=1000000010.0;
		check(3);
		while((r-ul)/(max(ul,1.0))>0.000000001)
		{
			double mid=(ul+r)/2;
			if(check(mid))
				r=mid;
			else
				ul=mid;
		}
		printf("%.12lf\n",ul);
	}
}