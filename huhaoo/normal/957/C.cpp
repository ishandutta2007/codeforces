#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define N 100010
int n,u,a[N],p;
double ans=-1.0;
int main()
{
	n=read();
	u=read();
	fr(i,1,n)a[i]=read();
	fr(i,1,n-2)
	{
		int k=upper_bound(a+1,a+n+1,a[i]+u)-a-1,j=i+1;
		//printf("%d %d %d %d %d %d\n",k,j,i,a[k],a[j],a[i]);
		if(j>=k)continue;
		ans=max(ans,double(a[k]-a[j])/double(a[k]-a[i]));
		p=1;
	}
	if(!p)printf("-1\n");
	else printf("%.15lf\n",ans);
	return 0;
}
/*
3 100000
1 11 12
*/