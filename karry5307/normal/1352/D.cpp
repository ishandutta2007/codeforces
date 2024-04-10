#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll test,n,u,v,sum,lst,tot,turn,l,r,cur;
ll x[MAXN];
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
	n=read(),u=v=0,l=1,r=n,sum=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),sum+=x[i];
	}
	turn=tot=1,u+=x[1],sum-=x[1],lst=x[1],l=2;
	while(l<=r)
	{
		if(sum<=lst)
		{
			tot++,turn?v+=sum:u+=sum;
			break;
		}
		cur=0;
		if(turn)
		{
			while(cur<=lst)
			{
				sum-=x[r],cur+=x[r--];
			}
			v+=cur;
		}
		else
		{
			while(cur<=lst)
			{
				sum-=x[l],cur+=x[l++];
			}
			u+=cur;
		}
		lst=cur,turn^=1,tot++;
	}
	printf("%d %d %d\n",tot,u,v);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}