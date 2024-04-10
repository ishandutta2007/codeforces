#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const ll MAXN=2e5+51;
ll cnt,cur;
ll sum[MAXN>>1],num[MAXN];
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
	for(register int i=0;i<(cnt>>1);i++)
	{
		sum[i]=read();
	}
	num[cnt-1]=sum[0];
	for(register int i=1;i<(cnt>>1);i++)
	{
		cur=min(sum[i]-num[i-1],num[cnt-i]);
		num[i]=sum[i]-cur,num[cnt-i-1]=cur;
	}
	for(register int i=0;i<cnt;i++)
	{
		printf("%I64u ",num[i]);
	}
}