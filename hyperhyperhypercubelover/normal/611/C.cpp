#include<cstdio>

char s[555][555];
int a[555][555];
int b[555][555];

int main()
{
	int w,x,y,z;
    int i,j,n,m,r;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
		{
			if(s[i][j]=='.'&&s[i-1][j]=='.')a[i][j]++;
			if(s[i][j]=='.'&&s[i][j-1]=='.')b[i][j]++;
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
		}
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&w,&x,&y,&z);
        printf("%d\n",a[y][z]-a[w][z]-a[y][x-1]+a[w][x-1]+b[y][z]-b[y][x]-b[w-1][z]+b[w-1][x]);
	}
}