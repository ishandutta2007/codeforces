#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e3+51;
ll cnt,x;
vector<ll>q;
ll p[MAXN],res[MAXN];
vector<ll>f[MAXN];
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
inline ll dfs(ll node)
{
	ll res=node>0;
	for(register int to:f[node])
	{
		res+=dfs(to);
	}
	if(node)
	{
		if(p[node]>=res)
		{
			puts("NO"),exit(0);
		}
		q.insert(q.begin()+p[node],node);
	}
	return res;
}
int main()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		x=read(),p[i]=read(),f[x].push_back(i);
	}
	dfs(0),puts("YES");
	for(register int i=0;i<q.size();i++)
	{
		res[q[i]]=i+1;
	}
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",res[i]);
	}
}