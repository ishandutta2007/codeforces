#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define iter iterator  
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,st,r,n,m;
string str;
ll vis[MAXN],deg[MAXN],res[MAXN],g[MAXN][3];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
} 
inline void dfs(ll x,ll fa)
{
	res[++r]=x,vis[x]=1;
	for(register int i=1;i<=g[x][0];i++)
	{
		if(g[x][i]!=fa)
		{
			dfs(g[x][i],x);
		}
	}
}
inline void solve()
{
	cin>>str,st=0,r=0;
	for(register int i=0;i<str.length()-1;i++)
	{
		n=str[i]-'a'+1,m=str[i+1]-'a'+1;
		if(n!=g[m][1]&&n!=g[m][2]&&g[m][0]==2||m!=g[n][1]&&m!=g[n][2]&&g[n][0]==2)
		{
			return (void)puts("NO");
		}
		if(n!=g[m][1]&&n!=g[m][2])
		{
			g[m][++g[m][0]]=n,g[n][++g[n][0]]=m;
		}
	}
	for(register int i=1;i<=26;i++)
	{
		if((!g[i][0]||g[i][0]==1)&&!vis[i])
		{
			dfs(i,0);
		}
	}
	if(r!=26)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		for(register int i=1;i<=26;i++)
		{
			printf("%c",res[i]+'a'-1);
		}
		puts("");
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
		memset(vis,0,sizeof(vis)),memset(res,0,sizeof(res));
		memset(g,0,sizeof(g));
	}
}