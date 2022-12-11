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

const int maxn=1e5+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt=1,start[maxn],del[maxn<<1],rd[maxn];

inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,k;

inline void init()
{
	n=read();k=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);rd[u]++;
		addedge(v,u);rd[v]++;
	}
}

queue<int>q;
int f[maxn],fs[maxn];

inline void doing()
{
	REP(i,1,n)if(rd[i]==1)q.push(i),fs[i]=3;
	int t=0,lst=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(fs[u]<3)puts("NO"),exit(0);
		chkmax(lst,f[u]);
		EREP(i,u)if(!del[i])
		{
			int v=e[i].v;
			del[i]=del[i^1]=1;
			if(!f[v])
			{
				f[v]=f[u]+1; fs[v]=1;
			}
			else if(f[v]!=f[u]+1)puts("NO"),exit(0);
			else {
				fs[v]++;
			}
			rd[v]--;
			if(rd[v]==1)q.push(v);
		}
	}
	if(lst==k)puts("YES");
	else puts("NO");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}