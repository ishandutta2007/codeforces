#include<cstdio>

char a[111][111];
int t[111];
int tt[111];

int main()
{
	int i,j,k,n,m,r=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",a[i]);
    for(j=0;j<m;j++)
	{
		for(i=1;i<n;i++)if(t[i]==t[i-1]&&a[i][j]<a[i-1][j])break;
		if(i==n)
		{
			k=0;
            for(i=0;i<n;i++)
			{
				while(a[i][j]!=a[k][j]||t[i]!=t[k])k++;
                tt[i]=k;
			}
            for(i=0;i<n;i++)t[i]=tt[i];
		}
		else r++;
	}
	printf("%d",r);
}