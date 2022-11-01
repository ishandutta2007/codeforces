#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
string mv="lrud";
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
inline void moveNotEmpty(ll dir,ll t=1)
{
	for(register int i=0;i<t;i++)
	{
		printf("%cs%ct",mv[dir],mv[dir^1]);
	}
}
inline void moveIf(ll dir,ll x,ll t=1)
{
	for(register int i=0;i<t;i++)
	{
		printf(x?"%c%cst":"%c%ct",mv[dir],mv[dir^1]);
	}
}
inline void copy(ll dir,ll t=1)
{
	for(register int i=0;i<t;i++)
	{
		printf("%c10%ct",mv[dir],mv[dir^1]);
	}
}
inline void op(const char *ch)
{
	printf(ch);
}
int main()
{
    moveNotEmpty(0,32);
    for(register int i=1;i<=32;i++)
    {
    	op("0l");
	}
	op("r"),moveNotEmpty(1,64),op("lu"),moveNotEmpty(0,32);
    for(register int i=1;i<=32;i++)
    {
    	op("0l");
	}
	op("r"),moveNotEmpty(1,64),op("lu0dd");
	for(register int i=1;i<=32;i++)
	{
		op("u"),copy(1),op("dl"),copy(1,2),op("drrel1l0l1l0uuu");
		moveIf(1,1),op("d"),moveIf(1,1),op("d"),moveIf(1,1),op("d");
		for(register int j=1;j<=4;j++)
		{
			moveNotEmpty(1),moveNotEmpty(0),copy(1);
		}
		op("l"),copy(0,3),copy(3),op("u"),op("0r0r1r1llluuu");
		moveIf(1,1),op("d"),moveIf(1,1),op("d"),moveIf(1,1),op("d");
		for(register int j=1;j<=4;j++)
		{
			moveNotEmpty(1),moveNotEmpty(0),copy(1);
		}
		op("l"),copy(0,3),copy(2,3),copy(0),op("dd");
	}
	printf("ddr"),moveIf(1,0,32);
}