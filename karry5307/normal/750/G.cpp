#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=61;
ll lg2;
li num,tmp,tmp2,res,p; 
li power[MAXN],dp[MAXN][MAXN<<1][2];
inline li read()
{
    register li num=0,neg=1;
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
inline li DP(li x,li y,ll u,ll v,ll w)
{
	ll t;
	memset(dp[p],0,sizeof(dp[p])),dp[p][0][0]=1;
	for(register int i=1;i<=log2(x)+1;i++)
	{
		t=(x>>i)&1,p^=1,memset(dp[p],0,sizeof(dp[p]));
		for(register int j=0;j<=(i-1)<<1;j++)
		{
			for(register int k=0;k<2;k++)
			{
				if(dp[p^1][j][k])
				{
					for(register int m=0;m<2;m++)
					{
						if(!m||i<u)
						{
							for(register int n=0;n<2;n++)
							{
								if(!n||i<v)
								{
									if(((k+m+n)&1)==t)
									{
										dp[p][j+m+n][(k+m+n)>>1]+=dp[p^1][j][k];
									}
								}
							}
						}
					}
				}
			}
		}	
	}
	return dp[p][w][0];
}
int main()
{
	num=read(),power[0]=1;
	while(num>=power[lg2-1])
	{
		power[lg2+1]=power[lg2]<<1,lg2++;
	} 
	lg2--;
	for(register int i=1;i<=lg2;i++)
	{
		if((tmp=num/(power[i]-1))>0)
		{
			tmp2=num-tmp*(power[i]-1);
			for(register int j=i-1;j>=0;j--)
			{
				tmp2=tmp2-power[j]+1>=0?tmp2-power[j]+1:tmp2;
			} 
			if(!tmp2)
			{
				res++;
			}
		}
	}
	for(register int i=1;i<=lg2;i++)
	{
		for(register int j=1;power[j]-1<=num;j++)
		{
			if((tmp=(num-power[j]+1)/(power[i+1]+power[j+1]-3))>0)
			{
				tmp2=(num-power[j]+1)-tmp*(power[i+1]+power[j+1]-3);
				if(!tmp2)
				{
					res++;
					continue;
				}
				if(i*j==1)
				{
					res+=(tmp2==tmp*5+1);
					continue;
				}
				for(register int k=1;k<=i+j;k++)
				{
					if(~(tmp2+k)&1)
					{
						res+=DP(tmp2+k,tmp,i,j,k);
					}
				}
			} 
		}	
	} 
	printf("%lld",res);
}