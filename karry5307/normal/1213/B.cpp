#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,cnt,minn,res;
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
	test=read();
	for(register int i=0;i<test;i++)
	{
		cnt=read(),minn=0x3f3f3f3f,res=0;
		for(register int j=0;j<cnt;j++)
		{
			num[j]=read();
		}
		for(register int j=cnt-1;j>=0;j--)
		{
			if(minn>num[j])
			{
				minn=num[j];
			}
			if(minn<num[j])
			{
				res++;
			}
		}
		printf("%d\n",res);
	}
}