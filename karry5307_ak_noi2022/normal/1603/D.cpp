#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool is_prm[200000];int prm[200000],pcnt;long long phi[200000];
//pair<int,long long> D[150000];

const long long INF=1e17;

void init_mu(int n)
{
	for(int i=2;i<=n;i++)is_prm[i]=1;
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(is_prm[i])
		{
			prm[++pcnt]=i,phi[i]=i-1;
		}
		for(int j=1;j<=pcnt&&i*prm[j]<=n;j++)
		{
			is_prm[i*prm[j]]=0;
			if(i%prm[j]==0)
			{
				phi[i*prm[j]]=phi[i]*prm[j];break;
			}
			phi[i*prm[j]]=phi[i]*(prm[j]-1);
		}
		//printf("%d\n",maxp[4]);
	}
	//for(int i=1;i<=n;i++)printf("%lld ",phi[i]);puts("");
	for(int i=2;i<=n;i++)phi[i]+=phi[i-1];
	//for(int i=1;i<=n;i++)printf("%lld ",phi[i]);puts("");
	//puts("MAXP");
	//for(int i=1;i<=n;i++)printf("%d ",maxp[i]);puts("");
	/*for(int i=1;i<=n;i++)
	{
		int l=1,r=0;
		while(l<=i)
		{
			D[i].push_back(make_pair(l,0));r=i/(i/l);l=r+1;
		}
		D[i].push_back(make_pair(i+1,0));
		for(int j=D[i].size()-2;j>=0;j--)D[i][j].second=D[i][j+1].second+(D[i][j+1].first-D[i][j].first)*phi[i/D[i][j].first];
	}*/
}

long long cost(int x,int y)
{
	if(x>y)return INF;
	long long ans=0;
	int l=x,r=0;
	while(l<=y)
	{
		r=y/(y/l);ans+=(r-l+1)*phi[y/l];l=r+1;
	}
	return ans;
}

long long dp[200000][20];

int p[200000];

void calc(int l,int r,int x,int y,int k)
{
	if(l>r)return;
	if(x==y){for(int i=l;i<=r;i++)p[i]=x;return;}
	int cur=(l+r)>>1;
	long long val=cost(x,cur),minn=val+dp[x-1][k-1];int pos=x;
	for(int i=x+1;i<=y&&i<=cur;i++)
	{
		val-=phi[cur/(i-1)];//?
		if(minn>val+dp[i-1][k-1])minn=val+dp[i-1][k-1],pos=i;
	}
	p[cur]=pos;calc(l,cur-1,x,p[cur],k),calc(cur+1,r,p[cur],y,k);
}

void init(int N,int K)
{
	init_mu(N);//puts("OK");
	for(int i=1;i<=N;i++)dp[i][0]=INF;
	for(int i=1;i<=K;i++)
	{
		calc(0,N,1,N,i);
		for(int j=0;j<=N;j++)dp[j][i]=min(INF,dp[p[j]-1][i-1]+cost(p[j],j));
	}
}

int main()
{
	init(100000,20);
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0,k=0;scanf("%d%d",&n,&k);if(k>=20){printf("%d\n",n);continue;}
		printf("%lld\n",dp[n][k]);
	}
}