#include<cstdio>

int a[200001];
int b[200001];
int d[200001],dn;

int p[200001][20];
int q[200001][20];

int main()
{
	int x,y,r=0;
	int i,j,n,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
    a[n]=2100000000;
    b[n]=0;
    d[dn++]=n;
    p[n][0]=n;
    q[n][0]=0;
	for(i=n-1;i>=0;i--)
	{
        while(a[d[dn-1]]+b[d[dn-1]]<=a[i]+b[i])dn--;
		p[i][0]=d[dn-1];
        if(a[d[dn-1]]<=a[i]+b[i])q[i][0]=0;
        else q[i][0]=a[d[dn-1]]-a[i]-b[i];
		d[dn++]=i;
	}
    for(j=1;j<20;j++)for(i=n;i>=0;i--)
	{
		p[i][j]=p[p[i][j-1]][j-1];
		q[i][j]=q[i][j-1]+q[p[i][j-1]][j-1];
	}
	//for(i=0;i<n;i++)for(j=0;j<5;j++)printf("%d %d : %d %d\n",i,j,p[i][j],q[i][j]);
    scanf("%d",&m);
    while(m--)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		j=x;
		r=0;
        for(i=19;i>=0;i--)if(p[j][i]<=y)
		{
			r+=q[j][i];
			j=p[j][i];
		}
		printf("%d\n",r);
	}
}