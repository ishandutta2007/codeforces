#include<bits/stdc++.h>
using namespace std;
int n,t,i,j,f[2005][2005],p[2005][26],q[2005][26];
char a[2005],b[2005];
int dfs(int x,int y)
{
	if(x==0&&y==0)
		return 0;
	if(f[x][y]!=-1)
		return f[x][y];
	int s=1<<30;
	if(x)
		if(a[x]==b[y])
			s=min(s,dfs(x-1,y-1));
	if(p[x+1][b[y]-'a']>q[y+1][b[y]-'a'])
		s=min(s,dfs(x,y-1));
	s=min(s,dfs(x-1,y)+1);
	return f[x][y]=s;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		memset(p[n+1],0,sizeof(p[n+1]));
		memset(q[n+1],0,sizeof(q[n+1]));
		for(i=n;i>=1;--i)
		{
			for(j=0;j<26;++j)
			{
				p[i][j]=p[i+1][j];
				q[i][j]=q[i+1][j];
			}
			++p[i][a[i]-'a'];
			++q[i][b[i]-'a'];
		}
		for(i=0;i<26;++i)
			if(p[1][i]!=q[1][i])
				break;
		if(i<26)
		{
			puts("-1");
			continue;
		}
		for(i=0;i<=n;++i)
			for(j=0;j<=n;++j)
				f[i][j]=-1;
		cout<<dfs(n,n)<<endl;
	}			
}