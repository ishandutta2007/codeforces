#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,cnt,sum,f0,s,f;
ll num[MAXN];
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
	cnt=read(),sum=0,f0=f=0,s=cnt+1;
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read(),sum+=num[i];
	}
	for(register int i=1;i<=cnt;i++)
	{
		num[i]+=num[i-1];
	}
	num[cnt+1]=1e9+7;
	for(register int i=1;i<=cnt;i++)
	{
		if(!(i==cnt&&f==0)&&num[i]-num[f]>=sum)
		{
			f0=1;
			break;
		}
		if(i==cnt&&f==0&&num[i]-num[s]>=sum)
		{
			f0=1;
			break;
		}
		if(num[i]<num[f])
		{
			s=f,f=i;
		}
		else
		{
			if(num[i]<num[s])
			{
				s=i;
			}
		}
	}
	puts(f0?"NO":"YES");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}