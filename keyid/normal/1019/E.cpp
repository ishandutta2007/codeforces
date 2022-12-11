#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double ld;

#define pb push_back

const int MAXN=100005;

struct edge
{
	int to,a,b;
};

struct Point
{
	LL x,y;

	Point(){}
	Point(LL x,LL y):x(x),y(y){}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	Point operator + (const Point &b) const
	{
		return Point(x+b.x,y+b.y);
	}

	bool operator == (const Point &b) const
	{
		return x==b.x&&y==b.y;
	}
};

struct cmp
{
	bool operator () (const vector <Point> &a,const vector <Point> &b) const
	{
		return a.size()>b.size();
	}
};

vector <edge> G[MAXN];
vector <Point> p,tmp;
int root,sum,maxson[MAXN];
bool vis[MAXN];

bool cmpp(const Point &a,const Point &b)
{
	return a.x!=b.x?a.x<b.x:a.y>b.y;
}

int getroot(int u,int fa)
{
	int su=1;
	maxson[u]=0;
	for (auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa&&!vis[v])
		{
			int sv=getroot(v,u);
			su+=sv;
			maxson[u]=max(maxson[u],sv);
		}
	}
	maxson[u]=max(maxson[u],sum-su);
	if (maxson[u]<maxson[root])
		root=u;
	return su;
}

int calsize(int u,int fa)
{
	int s=1;
	for (auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa&&!vis[v])
			s+=calsize(v,u);
	}
	return s;
}

void work(int u,int fa,LL a,LL b)
{
	tmp.pb({a,b});
	for (auto &e:G[u])
	{
		int v=e.to;
		if (v!=fa&&!vis[v])
			work(v,u,a+e.a,b+e.b);
	}
}

vector <Point> H;
Point h[MAXN];

LL judge(const Point &a,const Point &b)
{
	ld ret=(ld)a.x*b.y-(ld)a.y*b.x;
	if (abs(ret)>1e18)
		return ret<0?-1:1;
	return a.x*b.y-a.y*b.x;
}

void Graham(vector <Point> &P)
{
	sort(P.begin(),P.end(),cmpp);
	P.resize(unique(P.begin(),P.end())-P.begin());
	H.resize(P.size());
	int HTop=0;
	for (int i=0;i<P.size();i++)
	{
		while (HTop>1&&judge(P[i]-H[HTop-2],H[HTop-1]-H[HTop-2])<=0)
			HTop--;
		H[HTop++]=P[i];
	}
	H.resize(HTop);
	P=H;
}

void minkowski(const vector <Point> &h1,const vector <Point> &h2)
{
	p.pb(h1[0]+h2[0]);
	for (int i=1,j=1;i<h1.size()||j<h2.size();)
		if (j==h2.size()||(i<h1.size()&&judge(h1[i]-h1[i-1],h2[j]-h2[j-1])<0))
			p.pb(h1[i++]+h2[j-1]);
		else
			p.pb(h1[i-1]+h2[j++]);
}

void dfs(int u)
{
	vis[u]=true;
	priority_queue <vector<Point>,vector < vector<Point> >,cmp> q;
	for (auto &e:G[u])
		if (!vis[e.to])
		{
			tmp.clear();
			work(e.to,u,e.a,e.b);
			Graham(tmp);
			q.push(tmp);
			for (auto &x:tmp)
				p.pb(x);
		}
	while (q.size()>1)
	{
		auto v1=q.top();q.pop();
		auto v2=q.top();q.pop();
		minkowski(v1,v2);
		for (auto &x:v2)
			v1.pb(x);
		Graham(v1);
		q.push(v1);
	}
	for (auto &e:G[u])
	{
		int v=e.to;
		if (!vis[v])
		{
			root=0;
			sum=calsize(v,u);
			getroot(v,u);
			dfs(root);
		}
	}
}

LL cal(int x,const Point &p)
{
	return x*p.x+p.y;
}

int main()
{
	//freopen("read.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	if (n==1)
	{
		for (int i=0;i<m;i++)
			printf("0 ");
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		int u,v,a,b;
		scanf("%d%d%d%d",&u,&v,&a,&b);
		G[u].pb({v,a,b});
		G[v].pb({u,a,b});
	}
	maxson[root=0]=INT_MAX;
	sum=n;
	getroot(1,0);
	dfs(root);
	Graham(p);
	int head=0;
	for (int i=0;i<m;i++)
	{
		while (head+1<p.size()&&cal(i,p[head])<=cal(i,p[head+1]))
			head++;
		printf("%lld ",cal(i,p[head]));
	}
	return 0;
}