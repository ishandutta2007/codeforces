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

const int N=2000+5,M=2000000+5;
struct Point
{
	int x,y;
};
Point operator -(const Point &a,const Point &b)
{
	return (Point){a.x-b.x,a.y-b.y};
}
s64 operator *(const Point &a,const Point &b)
{
	return (s64)a.x*b.y-(s64)b.x*a.y;
}
Point p[N];
struct Edge
{
	Point p;int i,j;
};
Edge e[M];
Point qp[N];int q[N],id[N];

int n;
void check(const Edge &e,s64 s)
{
	Point np=e.p;
	s+=np*p[e.i];
	int l=0,r=n;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(np*qp[mid]>=s)r=mid;
		else l=mid;
	}
	if(np*qp[r]==s)
	{
		puts("Yes");
auto P=[&] (const Point &p) { printf("%d %d\n",p.x,p.y);  };
		P(p[e.i]);
		P(p[e.j]);
		P(qp[r]);		
		exit(0);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	s64 s;
	cin>>n>>s;
	s*=2;
	rep(i,1,n){p[i].x=read();p[i].y=read();}

	sort(p+1,p+n+1,[&] (const Point &a,const Point &b) { return a.x!=b.x?a.x<b.x:a.y<b.y;  } );

	int tot=0;
	rep(i,1,n)
	rep(j,i+1,n)e[++tot]=(Edge){p[j]-p[i],i,j};
	sort(e+1,e+tot+1,[&] (const Edge &a,const Edge &b) { return a.p*b.p>0;  } );
	
	rep(i,1,n)q[i]=i;
	rep(i,1,n)
	{
		qp[i]=p[q[i]];
		id[q[i]]=i;
	}

	rep(h,1,tot)
	{
		int j=e[h].j,i=e[h].i;
		while(id[j]>id[i])
		{
			int k=q[id[j]-1];
			id[k]=id[j];
			q[id[j]]=k;
			qp[id[j]]=qp[id[k]];
			--id[j];
		}
		q[id[j]]=j;
		qp[id[j]]=p[j];
		q[id[i]]=i;
		qp[id[i]]=p[i];
		check(e[h],s);
	}
	puts("No");
}