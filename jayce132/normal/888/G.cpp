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

const int maxn=2e5+20;
const int inf=(1<<31)-1;

int n,a[maxn];
ll ans;

struct node {
	int ch[2],id;
};
node t[maxn*32];
int tot;

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
}

inline void insert(int x)
{
	int u=0;
	DREP(i,29,0)
	{
		int to=x>>i&1;
		int &v=t[u].ch[to];
		if(!v)v=++tot;
		u=v;
	}
}

int dfs(int u1,int u2,int dep)
{
	if(u1==0 || u2==0)return inf;
	if(dep==-1)return 0;
	if(t[u1].ch[0] && t[u2].ch[0] || t[u1].ch[1] && t[u2].ch[1])
		return min(dfs(t[u1].ch[0],t[u2].ch[0],dep-1),dfs(t[u1].ch[1],t[u2].ch[1],dep-1));
	else return (1<<dep)+min(dfs(t[u1].ch[0],t[u2].ch[1],dep-1),dfs(t[u1].ch[1],t[u2].ch[0],dep-1));
}

void solve(int u,int dep)
{
	if(t[u].ch[0])solve(t[u].ch[0],dep-1);
	if(t[u].ch[1])solve(t[u].ch[1],dep-1);
	if(t[u].ch[0] && t[u].ch[1])
		ans+=dfs(t[u].ch[0],t[u].ch[1],dep-1)+(1<<dep);
}

inline void doing()
{
	REP(i,1,n)insert(a[i]);
	solve(0,29);
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}