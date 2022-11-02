#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
bitset<151>bs;
ll n,x,res;
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
	n=read(),x=read(),bs.set();
	for(register int i=1;i<=n;i++)
	{
		bs.reset(read());
	}
	while(bs._Find_first()<x)
	{
		bs.reset(bs._Find_first()),res++;
	}
	printf("%d\n",res+(bs._Find_first()!=x));
}