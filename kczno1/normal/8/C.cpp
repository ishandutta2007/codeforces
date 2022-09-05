#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define mp make_pair
int sqr(int x)
{
	return x*x;
}
int dis(const pii &a,const pii &b)
{
	return sqr(a.first-b.first)+sqr(a.second-b.second);
}
const int N=24+1,S=1<<24;
int n;pii dp[S];
pii p[N];
int w[N][N];

pii dfs(int s)
{
	if(dp[s].first!=-1)return dp[s];
	rep(i,1,n)
	if(s&(1<<i-1))
	{
		int _s=s-(1<<i-1);
		dp[s]=mp(dfs(_s).first+w[i][i],i);
		rep(j,i+1,n)
		if(_s&(1<<j-1))chmin(dp[s],mp(dfs(_s-(1<<j-1)).first+w[i][j],j));
		return dp[s];
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d%d",&p[0].first,&p[0].second);
	cin>>n;
	rep(i,1,n)scanf("%d%d",&p[i].first,&p[i].second);
	rep(i,1,n)
	rep(j,i,n)w[i][j]=dis(p[0],p[i])+dis(p[i],p[j])+dis(p[j],p[0]);
	memset(dp,-1,sizeof(dp));
	dp[0].first=0;
	int s=(1<<n)-1;
	pii p=dfs(s);
	printf("%d\n",p.first);
	printf("%d",0);
	while(s)
	{
		p=dp[s];
		rep(i,1,n)
		if(s&(1<<i-1))
		{
			if(p.second==i)
			{
				printf(" %d",i);
				s-=1<<i-1;
			}
			else
			{
				printf(" %d %d",i,p.second);
				s-=(1<<i-1)+(1<<p.second-1);
			}
			break;
		}
		printf(" %d",0);
	}
}