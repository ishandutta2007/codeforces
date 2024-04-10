#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef double db;
const ll MAXN=1e3+51;
ll w,b;
db dp[MAXN][MAXN];
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
	w=read(),b=read();
	for(register int i=1;i<=w;i++)
	{
		dp[i][0]=1,dp[i][1]=1.0*i/(i+1);
	}
	for(register int i=1;i<=w;i++)
	{
		for(register int j=2;j<=b;j++)
		{
			dp[i][j]=1.0*i/(i+j);
			dp[i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*dp[i-1][j-2];
			if(j>=3)
			{
				dp[i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3];
			}
		}
	}
	printf("%.12lf",dp[w][b]);
}