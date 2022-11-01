#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,tot;
vector<ll>v[2];
char ch[MAXN];
ll res[MAXN];
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
inline void solve()
{
	n=read(),tot=0,scanf("%s",ch+1),memset(v,0,sizeof(v));
	for(register int i=1;i<=n;i++)
	{
		if(v[ch[i]&=1].empty())
		{
			v[ch[i]^1].push_back(res[i]=++tot);
			continue;
		}
		v[ch[i]^1].push_back(res[i]=v[ch[i]].back());
		v[ch[i]].pop_back();
	}
	printf("%d\n",tot);
	for(register int i=1;i<=n;i++)
	{
		printf("%d%c",res[i]," \n"[i==n]),res[i]=0;
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}