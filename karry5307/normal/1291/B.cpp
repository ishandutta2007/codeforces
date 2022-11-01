#include<bits/stdc++.h>
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define lwb lower_bound
#define upb upper_bound
using namespace std;
typedef int ll;
const ll MAXN=3e5+51;
ll test,cnt,flg;
ll num[MAXN],prefix[MAXN],suffix[MAXN];
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
	cnt=read();
	memset(prefix,0,sizeof(prefix)),memset(suffix,0,sizeof(suffix));
	prefix[0]=suffix[cnt+1]=1;
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();	
		if(num[i]>=i-1)
		{
			prefix[i]=1;
		}
		if(num[i]>=cnt-i)
		{
			suffix[i]=1;
		}
	}	
	for(register int i=cnt,j=1;i;i--,j++)
	{
		prefix[j]&=prefix[j-1],suffix[i]&=suffix[i+1];
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(prefix[i]&&suffix[i])
		{
			puts("Yes");
			return;
		}
	}
	puts("No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}