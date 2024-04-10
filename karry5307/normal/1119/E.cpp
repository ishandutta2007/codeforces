#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51;
ll cnt,res,ress;
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
int main()
{
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		num[i]=read();
	}
	for(register int i=cnt-1;i>=0;i--)
	{
		ress+=(num[i]>>1);
		if((num[i]&1)&&ress>0)
		{
			res++,ress--;
		}
	}
	printf("%lld",res+(ress<<1)/3);
}