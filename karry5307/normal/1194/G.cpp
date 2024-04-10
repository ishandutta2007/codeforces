#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=151,MOD=998244353;
map<pii,ll>f[2][2][11][11];
ll n,res;
ll d[MAXN],r1[11],r2[11];
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
inline void clr(ll x)
{
	for(register int i=0;i<10;i++)
	{
		for(register int j=0;j<10;j++)
		{
			f[x][0][i][j].clear(),f[x][1][i][j].clear();
		}
	}
}
inline ll DP(ll x,ll y)
{
	ll cur,nxt,c1,c2,d1,d2,s1,s2,s3,s4,g,r,res=0;
	memset(r1,0,sizeof(r1)),memset(r2,0,sizeof(r2));
	for(register int i=1;i*y<10;i++)
	{
		r1[i*x]=r2[i*y]=1<<i-1;
	}
	clr(0),f[0][0][0][0][{0,0}]=1;
	// mp[i][j][k][l][{m,n}]  i   i 
	// k  l  m,n   
	for(register int i=1;i<=n;i++)
	{
		clr(nxt=i&1),cur=nxt^1;
		for(register int j=0;j<2;j++)
		{
			for(register int r1=0;r1<10;r1++)
			{
				for(register int r2=0;r2<10;r2++)
				{
					for(auto k:f[cur][j][r1][r2])
					{
						tie(s1,s2)=k.first,r=k.second;
						if(!r)
						{
							continue;
						}
						for(register int l=0;l<10;l++)
						{
							d1=r1+l*x,c1=d1/10,d1%=10;
							d2=r2+l*y,c2=d2/10,d2%=10;
							g=d2!=d[i]?d2>d[i]:j;
							s3=s1|::r1[d1],s4=s2|::r2[d2];
							f[nxt][g][c1][c2][{s3,s4}]+=r;
							f[nxt][g][c1][c2][{s3,s4}]%=MOD;
						}
					}
				}
			}
		}
	}
	for(auto i:f[n&1][0][0][0])
	{
		tie(s1,s2)=i.first,s1&s2?res=(res+i.second)%MOD:1;
	}
	return res;
}
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for(register int i=1;i<=n;i++)
	{
		d[n+1-i]=ch[i]-48;
	}
	for(register int i=1;i<10;i++)
	{
		for(register int j=i+1;j<10;j++)
		{
			__gcd(i,j)==1?res=((li)res+2*DP(i,j))%MOD:1;
		}
	}
	printf("%d\n",(res+DP(1,1))%MOD);
}