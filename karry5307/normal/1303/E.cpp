#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define iter iterator  
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=451;
ll test,n,m,flg;
string s,t;
ll dp[MAXN][MAXN],nxt[MAXN][27];
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
inline bool check(ll x)
{
	for(register int i=0;i<x;i++)
	{
		for(register int j=x-1;j<=m;j++)
		{
			if(!i&&j==x-1)
			{
				dp[i][j]=0;
				continue;
			}
			else
			{
				if(i==0)
				{
					dp[i][j]=nxt[dp[i][j-1]][t[j]-'a'+1];
					continue;
				}
				if(j==x-1)
				{
					dp[i][j]=nxt[dp[i-1][j]][t[i]-'a'+1];
					continue;
				}
				dp[i][j]=min(nxt[dp[i-1][j]][t[i]-'a'+1],nxt[dp[i][j-1]][t[j]-'a'+1]);
			}
		}
	}
	return dp[x-1][m]<=n;
}
inline void solve()
{
	cin>>s>>t,n=s.length(),m=t.length(),s=" "+s,memset(nxt,0,sizeof(nxt));
	for(register int i=1;i<=26;i++)
	{
		nxt[n][i]=n+1,nxt[n+1][i]=n+1;
	}
	for(register int i=n-1;i>=0;i--)
	{
		for(register int j=1;j<=26;j++)
		{
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][s[i+1]-'a'+1]=i+1;
	}
	t=" "+t,flg=0;
	for(register int i=1;i<=m;i++)
	{
		flg|=check(i);
	}
	puts(flg?"Yes":"No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}