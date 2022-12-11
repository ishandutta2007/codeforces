#include<bits/stdc++.h>
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

const int maxn=5e5+20;

struct Edge {
	int u,v,w;
	int a,b;
};
Edge E[maxn];

vector<int>tow[maxn];

int n,m,maxw;

int fa[maxn];

int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
inline void merge(int x,int y){ x=fin(x); y=fin(y); fa[y]=x;}

inline void ksl()
{
	REP(i,1,n)fa[i]=i;
	REP(w,1,maxw)
	{
		for(int i:tow[w])
		{
			int u=E[i].u,v=E[i].v;
			E[i].a=fin(u);
			E[i].b=fin(v);
		}
		for(int i:tow[w])
		{
			merge(E[i].u,E[i].v);
		}
	}
}

inline void init()
{
	n=read();m=read();
	REP(i,1,m)
	{
		int u=read(),v=read(),w=read();
		E[i]=(Edge){u,v,w};
		tow[w].push_back(i);
		chkmax(maxw,w);
	}

	ksl();
	
}

inline bool cmp(int a,int b){ return E[a].w<E[b].w;}

int id[maxn];

inline void doing()
{
	int q=read();
	while(q--)
	{
		int k=read();
		REP(i,1,k)id[i]=read();
		sort(id+1,id+k+1,cmp);
		int flg=0,lst=0;
		REP(i,1,k)
		{
			if(i==k || E[id[i]].w!=E[id[i+1]].w)
			{
				REP(j,lst+1,i)
				{
					int u=E[id[j]].a,v=E[id[j]].b;
					fa[u]=u; fa[v]=v;
				}
				REP(j,lst+1,i)
				{
					int u=E[id[j]].a,v=E[id[j]].b;
					if(fin(u)==fin(v)){ flg=1;break;}
					merge(u,v);
				}
				lst=i;
			}
			if(flg)break;
		}
		if(!flg)puts("YES");
		else puts("NO");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("envy.in","r",stdin);
	freopen("envy.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}