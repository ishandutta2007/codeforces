#include<cstdio>

char a[111][111];
char d[111][111];
int x[11111];
int y[11111];
int z;
int n;

int valid(int x,int y)
{
	if(x<0||x>=n||y<0||y>=n)return 1;
    if(a[x][y]=='.')return 0;
    return 1;
}

void chg(int x,int y)
{
	if(x<0||x>=n||y<0||y>=n)return;
	a[x][y]='.';
}

int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		for(j=0;j<n;j++)if(a[i][j]=='o')
		{
			x[z]=i;
			y[z]=j;
			z++;
		}
	}
	for(i=-n+1;i<n;i++)for(j=-n+1;j<n;j++)
	{
		for(k=0;k<z;k++)if(!valid(x[k]+i,y[k]+j))break;
        if(k==z)d[i+n-1][j+n-1]='x';
        else d[i+n-1][j+n-1]='.';
	}
	d[n-1][n-1]='o';
	for(i=-n+1;i<n;i++)for(j=-n+1;j<n;j++)if(d[i+n-1][j+n-1]=='x')for(k=0;k<z;k++)chg(x[k]+i,y[k]+j);
	for(i=0;i<n;i++)for(j=0;j<n;j++)if(a[i][j]=='x')
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=0;i<2*n-1;i++)puts(d[i]);
}