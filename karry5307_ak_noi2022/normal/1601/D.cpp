#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

pair<int,int> P[600000];
int dp[600000];int p[600000];
vector<int> ev[600000];

struct BIT
{
	int c[600000],n;
	void init(int N){n=N;for(int i=1;i<=n;i++)c[i]=0;}
	int lowbit(int x){return x&-x;}
	void add(int x,int v){while(x<=n){c[x]+=v;x+=lowbit(x);}}
	int sum(int x){int ret=0;while(x){ret+=c[x];x-=lowbit(x);}return ret;}
}B;

int main()
{
	int n=0,d=0;scanf("%d%d",&n,&d);for(int i=1;i<=n;i++)scanf("%d%d",&P[i].first,&P[i].second);
	sort(P+1,P+n+1);
	for(int i=1;i<=n;i++)
	{
		p[i]=lower_bound(P+1,P+n+1,make_pair(P[i].second,0))-P-1;ev[p[i]].push_back(i);
	}
	B.init(n);for(int i=1;i<=n;i++)B.add(i,1);
	for(int i=n;i>=0;i--)
	{
		if(P[i].first<d||i==0){printf("%d\n",dp[i+1]);return 0;}
		dp[i]=dp[i+1];
		int pos=max(i,p[i]);
		for(int j=0;j<ev[i].size();j++)B.add(ev[i][j],-1);
		dp[i]=max(dp[i+1],1+dp[pos+1]+B.sum(pos)-B.sum(i));
	}
}