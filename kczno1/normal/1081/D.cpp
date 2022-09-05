#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=2e5+5;
int x[N];
int fa[N];bool have_x[N];
int tfa[N],mx[N],tot;
struct Edge
{
	int u,v,w;
};
Edge e[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,k){scanf("%d",x+i);have_x[x[i]]=1;}
	rep(i,1,n)fa[i]=i;
	rep(i,1,m)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,[&](const Edge &a,const Edge &b){return a.w<b.w;});
	tot=n;
	rep(i,1,m)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y)continue;
		++tot;
		fa[tot]=tot;
		mx[x]=have_x[y]*e[i].w;
		mx[y]=have_x[x]*e[i].w;
		fa[x]=tfa[x]=fa[y]=tfa[y]=tot;
		have_x[tot]=have_x[x]|have_x[y];
	}
	per(i,tot,1)chmax(mx[i],mx[tfa[i]]);
	rep(i,1,k)printf("%d ",mx[x[i]]);
}