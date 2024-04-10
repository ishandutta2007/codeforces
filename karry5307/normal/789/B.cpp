#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp;
ll st,q,l,m,res;
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
	st=read(),q=read(),l=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		mp[read()]=1;
	}
	for(register int i=1;i<=100;i++)
	{
		if(llabs(st)>l)
		{
			break;
		}
		res+=!mp[st],st*=q;
	}
	res<40?printf("%d\n",res):puts("inf");
}