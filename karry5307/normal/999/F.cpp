#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_set<ll>st;
ll n,kk,x,res;
ll f[5001][501],c[MAXN],r[MAXN],w[MAXN];
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
	n=read(),kk=read();
	for(register int i=1;i<=n*kk;i++)
	{
		c[read()]++;
	}
	for(register int i=1;i<=n;i++)
	{
		x=read(),r[x]++,st.insert(x);
	}
	for(register int i=1;i<=kk;i++)
	{
		w[i]=read();
	}
	for(register int i=1;i<=n*kk;i++)
	{
		f[i][1]=w[min(i,kk)];
		for(register int j=2;j<=n;j++)
		{
			for(register int k=1;k<=min(i,kk);k++)
			{
				f[i][j]=max(f[i][j],f[i-k][j-1]+w[k]);
			}
		}
	}
	for(register int i:st)
	{
		res+=f[c[i]][r[i]];
	}
	printf("%d\n",res);
}