#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
set<ll>s;
set<ll>::iterator it;
ll n,tp;
char ch;
ll st[MAXN],x[MAXN<<1],res[MAXN<<1];
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
	n=read();
	for(register int i=1;i<=2*n;i++)
	{
		cin>>ch;
		if(ch=='+')
		{
			s.insert(i);
			continue;
		}
		if(s.empty())
		{
			return puts("NO"),0;
		}
		x[i]=read();
		while(tp&&x[st[tp]]<x[i])
		{
			tp--;
		}
		if((it=s.lower_bound(st[tp]))==s.end())
		{
			return puts("NO"),0;
		}
		res[*it]=x[i],st[++tp]=i,s.erase(it);
	}
	puts("YES");
	for(register int i=1;i<=n*2;i++)
	{
		res[i]?printf("%d ",res[i]):1;
	}
}