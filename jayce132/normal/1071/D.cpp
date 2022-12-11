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
#include<bitset>
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=4e3+20;
const int maxp=1e8;
const int seed=101;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

const int prime[12]={0,2,3,5,7,11,13,17,19,23,29,31};

int n;
vector<int>b[maxn];
int bl[maxn],hs[maxn];
int tot;
vector<int>to[maxn];

map<int,int>mp;

inline int GetHash(vector<int>now)
{
	int hs=0;
	for(int x:now) hs=((ll)hs*seed+x)%mod;
	return hs;
}

void dfs(int u,vector<int>t,int ns,int lst,int All)
{
	if(u>8)return;
	b[++tot]=t;bl[tot]=ns; hs[tot]=GetHash(t); mp[hs[tot]]=tot;
	
	vector<int> v;
	REP(j,1,min(lst,22-All))
	{
		v=t; v.push_back(j); 
		dfs(u+1,v,ns*(j+1),j,All+j);
	}
}

int sx[maxn];
int td;
vector<int>tod[maxn];

int dis[600][maxn];
queue<int>q;

inline void bfs()
{
	REP(st,1,td)
	{
		memset(dis[st],inf,sizeof(dis[st]));
		for(int v:tod[st])dis[st][v]=0,q.push(v);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int v:to[u])
			{
				if(dis[st][v]>dis[st][u]+1)
				{
					dis[st][v]=dis[st][u]+1;
					q.push(v);
				}
			}
		}
	}
}

inline void prepare()
{
	//++tot; bl[tot]=1; hs[tot]=0; mp[hs[1]]=1; prd[1]=1;
	dfs(1,{},1,100,0);

	REP(i,1,tot)
	{
		vector<int>t;
		int len=b[i].size();
		REP(j,0,len-1)
		{
			t=b[i]; t[j]++;
			sort(t.begin(),t.end(),[](int a,int b){ return a>b;});
			int hs=GetHash(t);
			if(mp.find(hs)==mp.end())continue;
			int v=mp[GetHash(t)];
			to[i].push_back(v); to[v].push_back(i);
		}
		{
			t=b[i]; t.push_back(1);
			int hs=GetHash(t);
			if(mp.find(hs)==mp.end())continue;
			int v=mp[GetHash(t)];
			to[i].push_back(v); to[v].push_back(i);
		}
	}
	
	int t=0;
	REP(i,1,tot)sx[++t]=bl[i]; sort(sx+1,sx+t+1); t=unique(sx+1,sx+t+1)-(sx+1); td=t;
	REP(i,1,tot)bl[i]=lower_bound(sx+1,sx+t+1,bl[i])-(sx),tod[bl[i]].push_back(i);
	bfs();
}

inline int fj(int x)
{
	vector<int>a;
	for(int i=2;i*i<=x;i++)if(x%i==0)
	{
		int s=0;
		while(!(x%i))x/=i,s++;
		a.push_back(s);
	}
	if(x>1)a.push_back(1);
	sort(a.begin(),a.end(),[](int a,int b){ return a>b;});
	return mp[GetHash(a)];
}

inline void init()
{
	int A=fj(read()),B=fj(read());
	int ans=inf;
	REP(i,1,td)chkmin(ans,dis[i][A]+dis[i][B]);
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("dai.in","r",stdin);
	freopen("dai.out","w",stdout);
#endif
	prepare();
	int t=read();
	while(t--)
	{
		init();
	}
	return 0;
}