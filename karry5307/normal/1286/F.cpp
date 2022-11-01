#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=21;
ll cnt,u;
ll sz[1<<MAXN],g[1<<MAXN],p[1<<MAXN];
li f[1<<MAXN],h[1<<MAXN];
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
int main()
{
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		if(!(f[i]=read()))
		{
			i--,cnt--;
		}
	}
	for(register int i=1;i<(1<<cnt);i++)
	{
		sz[i]=sz[i>>1]+(i&1);
		for(register int j=0;j<cnt;j++)
		{
			if((i>>j)&1)
			{
				h[i]+=f[j];
			}
		}
		if((h[i]+sz[i]&1))
		{
			for(register int j=i;(j=((j-1)&i))&&!p[i];)
			{
				if(h[i]-sz[i]+1<=2*h[j]&&2*h[j]<=h[i]+sz[i]-1)
				{
					p[i]=1;	
				}	
			}	
		} 
	}
	for(register int i=1;i<(1<<cnt);i++)
	{
		if(p[i]&&!g[i])
		{
			g[i]=1,u=(1<<cnt)-i-1;
			for(register int j=u;j;j=(j-1)&u)
			{
				g[i|j]=max(g[i|j],g[j]+1);
			}
		}
	}
	printf("%d\n",cnt-g[(1<<cnt)-1]);
}