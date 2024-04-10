#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=551;
ll test,n,res,cur;
ll x[MAXN],barrel[MAXN];
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
	n=read(),res=0,memset(barrel,0,sizeof(barrel));
	for(register int i=1;i<=n;i++)
	{
		barrel[read()]++;
	}
	for(register int i=1;i<=100;i++)
	{
		cur=0;
		for(register int j=max(i-50,1);j<=50;j++)
		{
			if(i-j>=0&&j<=i-j)
			{
				cur+=(j==i-j?barrel[j]/2:min(barrel[j],barrel[i-j]));
			}
		}
		res=max(res,cur);
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}