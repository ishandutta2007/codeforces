#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5;
vector<int>lk[N];
int col[N],sz[N],fa[N],c[N][2];
bool rev[N];

namespace BIT
{
const int N=::N*2;
int c[N];
void add(int i,int x)
{
//	if(x==-13)
//		int yyx=1;
//	printf("%d %d\n",i,x);
	if(i)for(;i<N;i+=i&-i)c[i]+=x;
}
int query(int i)
{
	int ans=0;
	for(;i;i-=i&-i)ans+=c[i];
	return ans;
}
};

void dfs(int x,int fr)
{
	fa[x]=fr;sz[x]=1;
	for(auto y:lk[x])
	if(y!=fr)dfs(y,x);
}

void sc(int y,int x,bool d)
{
//	if(x==y)
//		int yyx=1;
	fa[x]=y;c[y][d]=x;
}
void rever(int x)
{
	rev[x]^=1;
}
bool get(int x)
{
	return x==c[fa[x]][1];
}
bool is_root(int x)
{
	return x!=c[fa[x]][0]&&x!=c[fa[x]][1];
}
void push_up(int x)
{
	sz[x]=sz[c[x][0]]+sz[c[x][1]]+1; 
}
void push_down(int x)
{
	if(rev[x])
	{
		swap(c[x][0],c[x][1]);
		rever(c[x][0]);
		rever(c[x][1]);
		rev[x]=0;
	}
}
void rot(int x)
{
	int y=fa[x];bool d=get(x);
	if(is_root(y))
	{
		col[x]=col[y];
		fa[x]=fa[y];
	}
	else sc(fa[y],x,get(y));
	sc(y,c[x][!d],d);
	sc(x,y,!d);
	push_up(y);
}
void splay(int x)
{
	static int st[N];
	int top=0;
	for(int i=x;st[++top]=i,!is_root(i);i=fa[i]);
	per(i,top,1)push_down(st[i]);
	while(!is_root(x))
	{
		int y=fa[x];
		if(is_root(y)){rot(x);break;}
		rot(get(x)==get(y)?y:x);rot(x);
	}
	push_up(x);
}
void change(int x,int nc)
{
//	int cnt=0;
	int y=0;
	while(x)
	{
//		++cnt;
		splay(x);
		BIT::add(col[x],-(sz[x]-sz[c[x][1]]));
		col[c[x][1]]=col[x];
		sc(x,y,1);
		push_up(x);
		y=x;
		x=fa[x];
//		cerr<<cnt<<endl;
	}
//	cerr<<cnt<<endl;
	col[y]=nc;
	BIT::add(nc,sz[y]);
	rever(y);
}
int query(int x)
{
	splay(x);
	return BIT::query(col[x]-1)+sz[c[x][1]]+1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	int n,m;
	cin>>n>>m;
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	dfs(n,0);
	rep(i,1,n)
	{	
		change(i,i);
	/*	rep(x,1,n)
		{
			splay(x);
			printf("%d%c",col[x]," \n"[x==n]);
		}*/
	}
	rep(i,1,m)
	{
		static char type[10];
		scanf("%s",type);
		if(*type=='u')
		{
			int x;
			scanf("%d",&x);
			change(x,n+i);
		}
		else
		if(*type=='w')
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",query(x)<query(y)?x:y);
		}
	}
}