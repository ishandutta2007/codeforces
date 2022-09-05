#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
double cmp(const double &x,const double &eps)
{
	return x<-eps?-1:x>eps;
}
const int N=1000+5,M=2000+5;
namespace FLOW
{
const int N=1000+5,M=2000+N+5;
struct Edge
{
	int to,next;double f;
};
Edge l[M*2];int e;
int t[N];
int n,S,T;
void add_e(int x,int y,const double &f)
{
	l[++e]=(Edge){y,t[x],f};t[x]=e;
	l[++e]=(Edge){x,t[y],0};t[y]=e;
}
int q[N],g[N];
bool bfs()
{
	rep(i,1,n)g[i]=N;
	g[S]=0;
	q[1]=S;
	int tail=1;
	rep(head,1,tail)
	{
		int x=q[head];
		if(x==T)return 1;
		for(int i=t[x];i;i=l[i].next)
		{
			int y=l[i].to;
			if(g[y]==N&&cmp(l[i].f,1e-11))
			{
				g[y]=g[x]+1;
				q[++tail]=y;
			}
		}
	}
	return 0;
}
int nt[N];
double dfs(int x,double f)
{
	if(x==T)return f;
	double f0=f;
	for(int &i=nt[x];i;i=l[i].next)
	{
		int y=l[i].to;
		if(g[y]==g[x]+1&&cmp(l[i].f,1e-11))
		{
			double d=dfs(y,min(f,l[i].f));
			l[i].f-=d;l[i^1].f+=d;f-=d;
			if(!cmp(f,1e-11))return f0;
		}
	}
	return f0-f;
}
double get_mf()
{
	double ans=0;
	while(bfs())
	{
		rep(i,1,n)nt[i]=t[i];
		for(int &i=nt[S];i;i=l[i].next)
		{
			int y=l[i].to;
			if(g[y]==g[S]+1&&cmp(l[i].f,1e-11))
			{
				double d=dfs(y,l[i].f);
				l[i].f-=d;l[i^1].f+=d;ans+=d;
			}
		}
	}
	return ans;
}
};

int n,m;
pii operator +(const pii &a,const pii &b)
{
	return pii(a.first+b.first,a.second+b.second);
}
pii operator -(const pii &a,const pii &b)
{
	return pii(a.first-b.first,a.second-b.second);
}
void operator +=(pii &a,const pii &b)
{
	a=a+b;
}
void operator -=(pii &a,const pii &b)
{
	a=a-b;
}
pii sx[N];
struct Edge
{
	int u,v;pii w;
};
Edge e[M];

double F(const double &t)
{
auto get_w=[&](const pii &w) { return w.first*t+w.second; };
	FLOW::e=1;
	FLOW::n=FLOW::T=n+2;
	FLOW::S=n+1;
	rep(i,1,n+2)FLOW::t[i]=0;
	rep(i,1,m)FLOW::add_e(e[i].u,e[i].v,get_w(e[i].w));
	double sx_tot=0;
	rep(i,1,n)
	{
		double w=get_w(sx[i]);
		if(w>0){FLOW::add_e(FLOW::S,i,w);sx_tot+=w;}
		else FLOW::add_e(i,FLOW::T,-w);
	}
	//printf("%.9f\n",FLOW::get_mf());
	return FLOW::get_mf()-sx_tot;
}

double erfen_r(double l)
{
	double r=1;
	rep(tmp,1,30)
	{
		double mid=(l+r)/2;
		if(!cmp(F(mid),1e-8))l=mid;
		else r=mid;
	}
	return r;
}
double erfen_l(double r)
{
	double l=0;
	rep(tmp,1,30)
	{
		double mid=(l+r)/2;
		if(!cmp(F(mid),1e-8))r=mid;
		else l=mid;
	}
	return l;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		int u,v,a,b,c,d;
		scanf("%d%d%d%d%d%d",&u,&v,&a,&b,&c,&d);
		pii l=pii(a,b),r=pii(c,d);
		e[i]=(Edge){u,v,r-l};
		sx[v]+=l;
		sx[u]-=l;
	}
//	printf("%.9f\n",F(0.8));
	double l=0,r=1;
	rep(tmp,1,100)
	{
		double m1=(2*l+r)/3,m2=(l+2*r)/3;
		if(F(m1)>F(m2))r=m2;
		else l=m1;
	}
//	printf("%.9f\n",r-l);
	printf("%.9f\n",erfen_r(l)-erfen_l(l));
}