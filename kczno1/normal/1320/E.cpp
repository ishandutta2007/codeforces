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
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
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

const int N=4e5+5,L=20;
int deep[N],fa[N],f[N][L],dfn[N];
vector<int>lk[N];

void dfs(int x,int fr)
{
	static int tot=0;
	dfn[x]=++tot;
	fa[x]=f[x][0]=fr;
	deep[x]=deep[fr]+1;
	rep(i,1,L-1)f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:lk[x])
	if(y!=fr)dfs(y,x);
}
int get_lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	per(j,L-1,0)
	if((deep[x]-deep[y])>>j)x=f[x][j];
	if(x==y)return x;
	per(j,L-1,0)
	if(f[x][j]!=f[y][j]){x=f[x][j];y=f[y][j];}
	return fa[x];
}

namespace KCZ
{
const s64 U=1e6;
int k,m,ak[N],am[N],s[N],q[N],st[N],top;
vector<int>lk[N];
int g[N],fr[N],leave[N],ans[N];
priority_queue<s64,vector<s64>,greater<s64>>heap;

void push(int x,int d,int f,int l)
{
	if(pii(g[x],fr[x])>pii(d,f))
	{
		g[x]=d;
		fr[x]=f;
		leave[x]=l;
		heap.push(d*U*U+f*U+x);
	}
}

void add_e(int x,int y)
{
	lk[x].push_back(y);
	lk[y].push_back(x);
}
void work()
{
//	puts("1");
	
	int k=read(),m=read();
	rep(i,1,k){ak[i]=q[i]=read();s[i]=read();}
	rep(i,1,m)am[i]=q[k+i]=read();
	sort(q+1,q+k+m+1,[&](int x,int y){return dfn[x]<dfn[y];});
	top=1;
	st[1]=1;
	rep(i,1,k+m)
	{
		int x=q[i];
		while(top>1&&deep[get_lca(x,st[top])]<deep[st[top-1]])
		{
			add_e(st[top],st[top-1]);
			--top;
		}
		if(st[top]==x)continue;
		int y=get_lca(x,st[top]);
		if(y!=st[top])
		{
			add_e(st[top],y);
			st[top]=y;
		}
		st[++top]=x;
	}
	rep(i,1,top-1)add_e(st[i+1],st[i]);
	
//	puts("1");
	
	rep(i,1,k)push(ak[i],0,i,0);
	vector<int>now;
	while(!heap.empty())
	{
		s64 v=heap.top();heap.pop();
		int x,d,f;
		x=v%U;
		v/=U;
		f=v%U;
		d=v/U;
		
		if(ans[x]!=-1)continue;
		//cerr<<x<<" "<<d<<" "<<f<<endl;
		ans[x]=f;
		now.push_back(x);
		for(auto y:lk[x])
		{
			int l=leave[x];
			int nd=abs(deep[x]-deep[y]);
			if(nd<=l)push(y,d,f,l-nd);
			else 
			{
				int d1=(nd-l+s[f]-1)/s[f];
				push(y,d+d1,f,d1*s[f]+l-nd);
			}
		}
	}
	
	rep(i,1,m)printf("%d%c",ans[am[i]]," \n"[i==m]);
	
	for(auto x:now){g[x]=N;ans[x]=-1;lk[x].clear();}
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
//	puts("1");
	int n=read();
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
//	puts("1");
	dfs(1,0);
//	puts("1");
	rep(i,1,n){KCZ::g[i]=N;KCZ::ans[i]=-1;}
	int q=read();
	while(q--)KCZ::work();
}