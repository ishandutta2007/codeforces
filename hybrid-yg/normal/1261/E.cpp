#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353;
int n,k,a[200005],i,j,mx,p[1005],num=1,c[1005][1005];
vector<int> s[1005];
void dfs(int i)
{
	if(i>n)
	{
		int j;
		printf("%d\n",n+1);
		for(i=1;i<=n+1;++i)
		{
			for(j=1;j<=n;++j)
				putchar(c[i][j]?'1':'0');
			putchar('\n');
		}
		exit(0);
	}
	int j;
	int y=a[i];
	bool flag=false;
	for(j=1;j<=num;++j)
	{
		y-=s[j].size();
		if(y<=0)
			break;
	}
	int t=j;
	if(y!=0)
	{
		y+=s[t].size();
		for(j=1;j<t;++j)
			for(k=0;k<s[j].size();++k)
				c[s[j][k]][i]=1;
		int m=0;
		for(j=0;j<y;++j)
		{
			c[s[t][j]][i]=1;
			p[++m]=s[t][j];
		}
		++num;
		for(j=y;j<s[t].size();++j)
			s[num].push_back(s[t][j]);
		s[t].clear();
		for(j=1;j<=m;++j)
			s[t].push_back(p[j]);
	}
	else
	{
		for(j=t+1;j<=num;++j)
			if(s[j].size()!=1)
				break;
		int pos;
		if(j<=num)
			pos=j;
		else
			pos=t+1;
		int a;
		for(j=1;j<=t;++j)
			if(s[j].size()!=1)
				break;
		if(j<=t)
			a=j;
		else
			a=1;
		int tmp=0;
		for(j=1;j<=t;++j)
			for(k=0;k<s[j].size()-(a==j);++k)
				c[s[j][k]][i]=1;
		c[s[pos][0]][i]=1;
		if(s[pos].size()>1)
		{
			tmp=s[pos][0];
			++num;
			for(j=1;j<s[pos].size();++j)
				s[num].push_back(s[pos][j]);
			s[pos].clear();
			s[pos].push_back(tmp);
		}
		else
		{
			tmp=s[a][s[a].size()-1];
			++num;
			for(j=0;j<s[a].size()-1;++j)
				s[num].push_back(s[a][j]);
			s[a].clear();
			s[a].push_back(tmp);
		}
	}
	dfs(i+1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=n+1;++i)
		s[1].push_back(i);
	num=1;
	dfs(1);
}