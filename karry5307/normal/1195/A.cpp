#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e4+51;
ll cnt,k,num,res,tmp,odd;
ll drink[MAXN];
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
	cnt=read(),k=read();
	for(register int i=0;i<cnt;i++)
	{
		drink[num=read()]++;
	} 
	for(register int i=1;i<=1000;i++)
	{
		if(drink[i]>=2)
		{
			tmp+=((drink[i]>>1)<<1);
			drink[i]&=1;
		}
	}
	for(register int i=1;i<=1000;i++)
	{
		if(drink[i]==1)
		{
			res++;
		}
	}
	printf("%d",tmp+((res+1)>>1));
}