#include <cstdio>

const int MAXN=100005;

double f[MAXN];

double quick_pow(double a,int x)
{
	double ret=1;
	while (x)
	{
		if (x&1) ret*=a;
		a*=a;
		x>>=1;
	}
	return ret;
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++) f[i]=quick_pow((double)i/m,n);
	double ans=f[1];
	for (int i=2;i<=m;i++) ans+=(f[i]-f[i-1])*i;
	printf("%.4f",ans);
	return 0;
}