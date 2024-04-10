#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=151;
ll n,cur,rr;
ll binom[MAXN],res[MAXN][MAXN];
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
	n=read();
	for(register int i=3;i<=100;i++)
	{
		binom[i]=i*(i-1)*(i-2)/6;
	}
	for(register int i=1;i<=100;i++)
	{
		if(n>=binom[i]&&n<=binom[i+1])
		{
			cur=rr=i,n-=binom[i];
			break;
		}
	}
	for(register int i=1;i<=cur;i++)
	{
		for(register int j=1;j<=cur;j++)
		{
			res[i][j]=i!=j;
		}
	}
	while(n)
	{
		rr++;
		for(register int i=2;i<=100;i++)
		{
			if(n>=i*(i-1)/2&&n<(i+1)*i/2)
			{
				cur=i,n-=i*(i-1)/2;
				break;	
			} 
		}
		for(register int i=1;i<=cur;i++)
		{
			res[rr][i]=res[i][rr]=1;
		}
	}
	printf("%d\n",rr);
	for(register int i=1;i<=rr;i++)
	{
		for(register int j=1;j<=rr;j++)
		{
			printf("%d",res[i][j]);
		}
		puts("");
	}
}