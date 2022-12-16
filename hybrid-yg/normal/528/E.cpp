#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int t,M,a,b,c,i,j,n;
struct str{
	int a,b,c;
}p[10005];
double ans;
bool cmp(str a,str b)
{
	if(a.b==0)
		return 1;
	if(b.b==0)
		return 0;
	return 1.0*a.a/a.b<1.0*b.a/b.b;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %d",&a,&b,&c);
		p[i]=(str){a,b,c};
	}
	sort(p+1,p+1+n,cmp);
	for(i=1;i<=n;++i)
	{
		double sx=0,sy=0;
		for(j=i%n+1;j!=i;j=j%n+1)
		{
			double x=(1.0*p[i].b*p[j].c-1.0*p[j].b*p[i].c)/(1.0*p[i].a*p[j].b-1.0*p[i].b*p[j].a);
			double y=(1.0*p[i].a*p[j].c-1.0*p[j].a*p[i].c)/(1.0*p[i].a*p[j].b-1.0*p[i].b*p[j].a);
			ans+=sx*y-sy*x;
			sx+=x;
			sy+=y;
		}
	}
	printf("%.12lf\n",fabs(ans/2)/n/(n-1)/(n-2)*3*2*1);
}