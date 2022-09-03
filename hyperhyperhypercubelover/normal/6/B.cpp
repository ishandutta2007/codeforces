#include<cstdio>

char a[111][111];
char s[4];

int px[4]={1,-1,0,0};
int py[4]={0,0,1,-1};

int chk[333];

int main()
{
    int i,j,k,n,m;
    scanf("%d%d%s",&n,&m,s);
    for(i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(a[i][j]==s[0])
	{
        for(k=0;k<4;k++)chk[a[i+px[k]][j+py[k]]]=1;
	}
	j=0;
	for(i=65;i<91;i++)if(i!=s[0]&&chk[i])j++;
	printf("%d",j);
}