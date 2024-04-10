#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,tot,kk,ptr,res;
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
inline void solve()
{
	kk=read();
	memset(num,0,sizeof(num)),tot=0,res=0;
	while(kk)
	{
		num[++tot]=kk%3,kk/=3;
	}
	for(register int i=tot;i;i--)
	{
		if(num[i]==2)
		{
			num[i]=0,ptr=i+1;
			for(register int j=i-1;j;j--)
			{
				num[j]=0;
			}
			while(num[ptr]==1)
			{
				num[ptr++]=0;
			}
			num[ptr]=1,tot=max(tot,ptr);
		}	
	} 
	for(register int i=tot;i;i--)
	{
		res=(res*3)+num[i];
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