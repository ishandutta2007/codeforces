#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=100005;
const int maxk=17;

vector< pair<int,int> > gr[maxn];
int tin[maxn],tout[maxn];
int up[maxn][maxk+1];
int kv[maxn];
int n,k;
int ans[maxn];
int timer;

void go1(int cur,int pr)
{
	up[cur][0]=max(0,pr);
	timer++;
	tin[cur]=timer;
	for (int i=0;i<gr[cur].size();i++) if (gr[cur][i].first!=pr) go1(gr[cur][i].first,cur);
	timer++;
	tout[cur]=timer;
}

int go2(int cur,int pr)
{
	int curt=0;
	for (int i=0;i<gr[cur].size();i++) if (gr[cur][i].first!=pr)
	{
		int t=go2(gr[cur][i].first,cur);
		ans[gr[cur][i].second]=t;
		curt+=t;
	}
	curt+=kv[cur];
	return curt;
}

inline bool ispred(int a,int b)
{
	return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}

int lca(int a,int b)
{
	if (ispred(a,b)) return a;
	for (int k=maxk;k>=0;k--)
	{
		int c=up[a][k];
		if (!ispred(c,b)) a=c;
	}
	return up[a][0];
}

void prep()
{
	for (int k=1;k<=maxk;k++)
	{
		for (int i=0;i<n;i++) up[i][k]=up[up[i][k-1]][k-1];
	}
}

int main()
{
	timer=0;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		gr[a].push_back(make_pair(b,i+1));
		gr[b].push_back(make_pair(a,i+1));
	}
	go1(0,-1);
	prep();
	scanf("%d",&k);
	for (int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		int c=lca(a,b);
		kv[a]++;
		kv[b]++;
		kv[c]-=2;
	}
	go2(0,-1);
	for (int i=1;i<=n-1;i++) printf("%d ",ans[i]);
	return 0;
}