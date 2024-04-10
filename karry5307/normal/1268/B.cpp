#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=3e5+51;
ll cnt,x,cur,black,white;
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
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		x=read(),cur^=1;
		if(cur==1)
		{
			white+=x>>1,black+=(x-(x>>1));
		}
		else
		{
			black+=x>>1,white+=(x-(x>>1));
		}
	}
	printf("%lld\n",min(black,white));
}