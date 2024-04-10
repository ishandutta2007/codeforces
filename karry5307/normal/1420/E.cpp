#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=85;
ll n,tot,res,m,r,c;
ll x[MAXN],cnt[2],pos[MAXN],f[MAXN][MAXN*MAXN][MAXN];
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
inline void chkmin(ll &x,ll y)
{
	x=x<y?x:y;
}
inline ll binom(ll n)
{
	return n*(n-1)/2;
}
int main()
{
	m=binom(n=read());
	for(register int i=1;i<=n;i++)
	{
		cnt[x[i]=read()]++;
		x[i]?pos[cnt[1]]=i:1;
	}
	if(!cnt[0])
	{
		for(register int i=0;i<=m;i++)
		{
			printf("%d ",0);
		}
		return 0;
	}
	res=tot=binom(cnt[0]),memset(f,0x3f,sizeof(f));
	for(register int i=1;i<=n;i++)
	{
		f[i][abs(pos[1]-i)][1]=binom(i-1);
		for(register int j=0;j<=m;j++)
		{
			for(register int k=1;k<=i&&k<cnt[1];k++)
			{
				r=cnt[1]-k;
				if(f[i][j][k]!=0x3f3f3f3f)
				{
					for(register int l=i+1;l<=n-r+1;l++)
					{
						c=j+abs(pos[k+1]-l);
						if(c<=m)
						{
							chkmin(f[l][c][k+1],f[i][j][k]+binom(l-i-1));
						}
					}
				}
			}
		}
	}
	for(register int j=0;j<=binom(n);j++)
	{
		for(register int i=cnt[1];i<=n;i++)
		{
			if(f[i][j][cnt[1]]!=0x3f3f3f3f)
			{
				chkmin(res,f[i][j][cnt[1]]+binom(n-i));
			}
		}
		printf("%d ",tot-res);
	}
}