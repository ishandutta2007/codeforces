#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,tot,x,y,swp;
vector<ll>v[MAXN],vg[2],g[2][2];
char ch[MAXN]; 
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
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for(register int i=1;i<=n;i++)
	{
		x=ch[i]=='R',vg[x^1].empty()?vg[x^1].push_back(++tot):(void)1;
		y=vg[x^1].back(),v[y].push_back(i);
		vg[x^1].pop_back(),vg[x].push_back(y);
	}
	printf("%d\n",tot-1);
	for(register int i=1;i<=tot;i++)
	{
		g[v[i].size()&1][ch[v[i].back()]=='R'].push_back(i);
	}
	if(!g[0][0].empty()&&!g[0][1].empty()&&g[1][0].empty()&&g[1][1].empty())
	{
		x=g[0][0].back(),y=g[0][1].back();
		v[x].back()<v[y].back()?1:(swap(x,y),swp=1);
		v[x].push_back(v[y].back()),v[y].pop_back();
		g[0][0].pop_back(),g[0][1].pop_back(),swp?swap(x,y):(void)1;
		g[1][0].push_back(y),g[1][1].push_back(x);
	}
	if(g[1][0].size()!=g[1][1].size())
	{
		x=g[1][1].size()>g[1][0].size();
	}
	else
	{
		x=g[0][0].size()>g[0][1].size();
	}
	while(!g[0][x^1].empty())
	{
		for(register int i:v[g[0][x^1].back()])
		{
			printf("%d ",i);
		}
		g[0][x^1].pop_back();
	}
	while(!g[1][x].empty())
	{
		for(register int i:v[g[1][x].back()])
		{
			printf("%d ",i);
		}
		g[1][x].pop_back();
		while(!g[0][x].empty())
		{
			for(register int i:v[g[0][x].back()])
			{
				printf("%d ",i);	
			}
			g[0][x].pop_back();
		}
		x^=1;
	}
}