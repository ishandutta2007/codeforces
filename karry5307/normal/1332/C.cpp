#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,kk,res,mx,sum;
ll occ[MAXN][26],sm[26];
char ch[MAXN];
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
	n=read(),kk=read(),scanf("%s",ch),res=0;
	for(register int i=0;i<n;i+=kk)
	{
		for(register int j=i,k=0;j<i+kk;j++,k++)
		{
			occ[k][ch[j]-'a']++;
		}
	}
	for(register int i=0;i<=(kk-1)>>1;i++)
	{
		if((kk&1)&&(i==((kk-1)>>1)))
		{
			mx=0,sum=0;
			for(register int j=0;j<26;j++)
			{
				sum+=occ[(kk-1)>>1][j];
				if(occ[(kk-1)>>1][j]>occ[(kk-1)>>1][mx])
				{
					mx=j;
				}
			}
			res+=sum-occ[(kk-1)>>1][mx];
			break;
		}
		mx=0,sum=0;
		for(register int j=0;j<26;j++)
		{
			sum+=(sm[j]=occ[i][j]+occ[kk-i-1][j]);
			if(sm[j]>sm[mx])
			{
				mx=j;
			}
		}
		res+=sum-sm[mx];
	}
	for(register int i=0;i<n;i++)
	{
		for(register int j=0;j<26;j++)
		{
			occ[i][j]=0;
		}
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}