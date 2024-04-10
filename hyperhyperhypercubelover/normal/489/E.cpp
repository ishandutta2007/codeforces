#include<cstdio>
#include<cmath>

double a[1001];
double b[1001];
double d[1001];
int vi[1001];

void print(int x)
{
	if(x)
	{
		print(vi[x]);
		printf("%d ",x);
	}
}

int main()
{
	double l,r,mid,m;
	int i,j,n;
	scanf("%d%lf",&n,&m);
	for(i=1;i<=n;i++)scanf("%lf%lf",&a[i],&b[i]);
	l=0;r=1e3;
    while(r-l>1e-9)
	{
        mid=(l+r)/2;
        for(i=1;i<=n;i++)
		{
			d[i]=-1e18;
			for(j=0;j<i;j++)if(d[j]-sqrt(fabs(a[i]-a[j]-m))+mid*b[i]>d[i])
			{
				vi[i]=j;
				d[i]=d[j]-sqrt(fabs(a[i]-a[j]-m))+mid*b[i];
			}
		}
		if(d[n]>0)r=mid;
		else l=mid;
	}
    print(n);
}