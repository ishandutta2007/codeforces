#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
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

const int maxn=3e5+20;

struct node {
	int ch[2];
	int sz;
};
node t[300000<<5];
int tot;

int n,a[maxn];

inline void insert(int x)
{
	int u=0;t[u].sz++;
	DREP(i,29,0)
	{
		int v=x>>i&1;

		if(!t[u].ch[v])t[u].ch[v]=++tot;
		u=t[u].ch[v];
		t[u].sz++;
	}
}

void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n)
	{
		int x=read();
		insert(x);
	}
}

int query(int x)
{
	int u=0,ans=0;
	t[u].sz--;
	DREP(i,29,0)
	{
		int to=x>>i&1,v=t[u].ch[to];
		if(v && t[v].sz>0)u=v;
		else u=t[u].ch[to^1],ans+=1<<i;
		t[u].sz--;
	}
	return ans;
}

inline void doing()
{
	REP(i,1,n)
	{
		printf("%d ",query(a[i]));
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}