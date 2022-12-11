#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=5020;
const int M=9;
const int mod=2520;

int id[maxn],vis[maxn],tot,choose[1<<10];
int TO[100][10];

inline int lcm(int a,int b){ return a*b/__gcd(a,b);}

void dfs(int u,int s)
{
	if(u>M)
	{
		if(!vis[s])id[++tot]=s,vis[s]=tot;
		return;
	}
	dfs(u+1,s);
	dfs(u+1,lcm(s,u));
}

ll dp[25][50][2521][2];

inline void prepare()
{
	dfs(1,1);
	REP(i,1,tot)
	{
		TO[i][0]=id[i];
		REP(j,1,9)TO[i][j]=lcm(id[i],j);
	}
}

inline ll calc(ll x)
{
	int a[30],len=0;
	if(!x)return 1;
	while(x)a[++len]=x%10,x/=10;
	memset(dp,0,sizeof(dp));
	dp[len+1][vis[1]][0][1]=1;
	
	DREP(i,len+1,2)REP(j,1,tot)REP(r,0,mod-1)
	{
		if(dp[i][j][r][1])
		{
			ll tmp=dp[i][j][r][1];int to;
			REP(t,0,a[i-1])
			{
				to=TO[j][t];
				dp[i-1][vis[to]][(r*10+t)%mod][t==a[i-1]]+=tmp;
			}
		}
		if(dp[i][j][r][0])
		{
			ll tmp=dp[i][j][r][0];int to;
			REP(t,0,M)
			{
				to=TO[j][t];
				dp[i-1][vis[to]][(r*10+t)%mod][0]+=tmp;
			}
		}
	}
	ll ans=0;
	REP(j,1,tot)REP(r,0,mod-1)if(!(r%id[j]))ans+=dp[1][j][r][0]+dp[1][j][r][1];
	return ans;
}

inline void init()
{
	ll l,r;
	cin>>l>>r;
	cout<<calc(r)-calc(l-1)<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("beautiful.in","r",stdin);
	freopen("beautiful.out","w",stdout);
#endif
	prepare();
	int t=read();
	while(t--)init();
	return 0;
}