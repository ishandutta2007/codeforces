#include <cstdio>

const int MAXN=2005;

bool row[MAXN],col[MAXN];
double f[MAXN][MAXN];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int r,c;m--;)
	{
		scanf("%d%d",&r,&c);
		row[r]=col[c]=true;
	}
	int cr=0,cl=0;
	for (int i=1;i<=n;i++)
	{
		if (!row[i]) cr++;
		if (!col[i]) cl++;
	}
	for (int i=1;i<=cr;i++)
		f[i][0]=f[i-1][0]+(double)n/i;
	for (int i=1;i<=cl;i++)
		f[0][i]=f[0][i-1]+(double)n/i;
	for (int i=1;i<=cr;i++)
		for (int j=1;j<=cl;j++)
		{
			double p1=(double)i/n,p2=(double)j/n;
			f[i][j]=(f[i-1][j]*p1*(1-p2)+f[i][j-1]*(1-p1)*p2+f[i-1][j-1]*p1*p2+1)/(1-(1-p1)*(1-p2));
		}
	printf("%.4f",f[cr][cl]);
	return 0;
}