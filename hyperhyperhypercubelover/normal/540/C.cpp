#include<cstdio>

char a[555][555];
int d[555][555];
int p,q,r,s;

void dfs(int x,int y)
{
	if(d[x][y])return;
    if((x!=p||y!=q)&&(x!=r||y!=s)&&a[x][y]!='.')return;
    d[x][y]=1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int main()
{
	int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%s",a[i]+1);
	scanf("%d%d%d%d",&p,&q,&r,&s);
	a[p][q]='.';
	dfs(p,q);
    if(!d[r][s])puts("NO");
    else if(p==r&&q==s&&(a[r+1][s]=='.')+(a[r-1][s]=='.')+(a[r][s+1]=='.')+(a[r][s-1]=='.')<1)puts("NO");
    else if(p==r&&q==s&&(a[r+1][s]=='.')+(a[r-1][s]=='.')+(a[r][s+1]=='.')+(a[r][s-1]=='.')>0)puts("YES");
    else if(a[r][s]=='X')puts("YES");
    else if((a[r+1][s]=='.')+(a[r-1][s]=='.')+(a[r][s+1]=='.')+(a[r][s-1]=='.')<2)puts("NO");
    else puts("YES");
}