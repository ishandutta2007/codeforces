#include<cstdio>

char a[111][111];
int c[111];
int d[111];
int v[111];
int r[111],rn;

int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%s",a[i]);
	for(i=0;i<n;i++)scanf("%d",&c[i]);
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)if(c[j]==d[j])break;
        if(j==n)break;
        if(v[j])
		{
			puts("-1");
			return 0;
		}
        v[j]=1;
        for(k=0;k<n;k++)if(a[j][k]=='1')d[k]++;
	}
	for(j=0;j<n;j++)if(v[j])r[rn++]=j;
	printf("%d\n",rn);
	for(j=0;j<rn;j++)printf("%d ",r[j]+1);
}