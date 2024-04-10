#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
ll test,length,x,bal,tmp,offset=100000;
li res;
string str;
ll barrel[MAXN<<1];
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
	length=read(),x=read(),cin>>str,res=bal=0;
	for(register int i=offset-length;i<=offset+length;i++)
	{
		barrel[i]=0;
	}
	for(register int i=0;i<length;i++)
	{
		bal+=str[i]=='0',bal-=str[i]=='1';
		barrel[bal+offset]++;
	}	
	if(!bal&&x<=length&&x>=-length&&barrel[x+offset])
	{
		puts("-1");
		return;
	}
	if(!bal)
	{
		puts("0");
		return;
	}
	tmp=abs(bal);
	if(!x)
	{
		res++;
	}
	for(register int i=offset-length;i<=offset+length;i++)
	{
		if((((bal>0)^(x<i-offset))||x==i-offset)&&(x%tmp+tmp)%tmp==((i-offset)%tmp+tmp)%tmp)
		{
			res+=barrel[i];
		}
	}
	printf("%lld\n",res);
} 
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}