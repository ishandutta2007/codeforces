#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=4000+5,M=2000+N+5,inf=1e9;
struct Edge
{
	int to,f,*nf;
};
Edge qa[M*2],*t[N],*nt[N];
int cnt[N];
struct Edge0
{
	int x,y,f;
	Edge *dy;
};
Edge0 edge0[M];
int n,S,T;

int g[N],q[N];
bool bfs()
{
	rep(i,1,n)g[i]=0;
	g[T]=N;
	int tail=1;
	q[1]=T;
	rep(head,1,tail)
	{
		int x=q[head];
		for(Edge *i=t[x];i<t[x+1];++i)
		if(*(i->nf))
		{
			int y=i->to;
			if(!g[y])
			{
				g[q[++tail]=y]=g[x]-1;
				if(y==S)return 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int f)
{
	if(x==T)return f;
	int f0=f;
	for(Edge* &i=nt[x];i<t[x+1];++i)
	if(i->f)
	{
		int y=i->to;
		if(g[y]<=g[x])continue;
		int del=dfs(y,min(f,i->f));
		i->f-=del;*(i->nf)+=del;
		if(!(f-=del))return f0;
	}
	return f0-f;
}
int solve(int m)
{
	rep(i,1,n)cnt[i]=0;
	rep(i,1,m){++cnt[edge0[i].x];++cnt[edge0[i].y];}
	t[1]=qa;
	rep(i,1,n)t[i+1]=t[i]+cnt[i];
	rep(i,1,m)
	{
		int x=edge0[i].x,y=edge0[i].y,f=edge0[i].f;
		--cnt[x];--cnt[y];
		edge0[i].dy=&t[x][cnt[x]];
		t[x][cnt[x]]=(Edge){y,f,&t[y][cnt[y]].f};
		t[y][cnt[y]]=(Edge){x,0,&t[x][cnt[x]].f};
	}
	int ans=0;
	while(bfs())
	{
		rep(i,1,n)nt[i]=t[i];
		ans+=dfs(S,inf);
	}
	return ans;
}

int main()
{

	int n1,n2,m;
	cin>>n1>>n2>>m;
	int n=n1+n2;
	::n=n+2;S=::n-1;T=::n;
	rep(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge0[i]=(Edge0){x,n1+y,1};
		++cnt[x];++cnt[n1+y];
	}
	int mn=cnt[1];
	rep(i,1,n)chmin(mn,cnt[i]);
	rep(k,0,mn)
	{
		rep(i,1,n1)edge0[m+i]=(Edge0){S,i,k};
		rep(i,n1+1,n)edge0[m+i]=(Edge0){i,T,k};
		/*cerr<<"Flow="<<*/solve(m+n);

		vector<int>*lk=new vector<int> [n+1];
		vector<int>ans;

		rep(i,1,m)
		if(!edge0[i].dy->f)ans.push_back(i);
		else 
		{
			int x=edge0[i].x,y=edge0[i].y;
			lk[x].push_back(i);
			lk[y].push_back(i);
		}
		rep(x,1,n)
		{
			int need=edge0[m+x].dy->f;
			rep(j,0,need-1)ans.push_back(lk[x][j]);
		}

		printf("%d ",(int)ans.size());
		for(auto i:ans)printf("%d ",i);
		puts("");
	}
}