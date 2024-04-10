#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll test,num;
double ang[451];
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
inline bool isInt(double x)
{
	return x==(ll)(x);
}
int main()
{
	test=read();
	for(register int i=3;i<=360;i++)
	{
		ang[i]=180.0/i;
	}
	for(register int i=0;i<test;i++)
	{
		num=read();
		for(register int j=3;j<=360;j++)
		{
			if(num<=180-360/j&&isInt(num/ang[j]))
			{
				printf("%d\n",j);
				break;
			}
		}
	}
}