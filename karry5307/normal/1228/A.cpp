#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll barrel[10];
ll l,r; 
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
inline bool check(ll x)
{
	memset(barrel,0,sizeof(barrel));
	while(x)
	{
		if(barrel[x%10])
		{
			return 0;
		}
		barrel[x%10]++,x/=10;
	}
	return 1;
}
int main()
{
	l=read(),r=read();
	for(register int i=l;i<=r;i++)
	{
		if(check(i))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}