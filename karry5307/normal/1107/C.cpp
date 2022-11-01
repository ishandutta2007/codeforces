#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
priority_queue<ll>q;
ll n,kk,totc,c;
li res;
ll l[MAXN],r[MAXN],x[MAXN];
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
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	scanf("%s",ch+1);
	for(register int i=1;i<=n;i++)
	{
		ch[i]!=ch[l[totc]]?l[++totc]=i:1,r[totc]=i;
	}
	for(register int i=1;i<=totc;i++)
	{
		while(!q.empty())
		{
			q.pop();
		}
		for(register int j=l[i];j<=r[i];j++)
		{
			q.push(x[j]);
		}
		for(register int j=1;j<=kk&&!q.empty();j++)
		{
			res+=q.top(),q.pop();
		}
	}
	printf("%lld\n",res);
}