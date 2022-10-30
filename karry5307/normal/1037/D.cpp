#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>ed[MAXN];
queue<ll>q;
ll nc,from,to,ptr,x;
ll ord[MAXN],rord[MAXN],ordd[MAXN];
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
	nc=read();
	for(register int i=0;i<nc-1;i++)
	{	
		from=read(),to=read();
		ed[from].push_back(to),ed[to].push_back(from);
	}
	for(register int i=1;i<=nc;i++)
	{
		rord[ord[i]=read()]=i;
	}
	for(register int i=1;i<=nc;i++)
	{
		sort(ed[i].begin(),ed[i].end(),[](ll x,ll y){return rord[x]<rord[y];});
	}
	q.push(1); 
	while(!q.empty())
	{
		ordd[++ptr]=x=q.front(),q.pop();
		for(auto i:ed[x])
		{
			if(rord[i]>rord[x])
			{
				q.push(i);
			}
		}
	}
	for(register int i=1;i<=nc;i++)
	{
		if(ord[i]^ordd[i])
		{
			return puts("No"),0; 
		}
	}
	puts("Yes");
}