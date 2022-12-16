#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int n,m,p,q,x[N],y[N],i,pl[N],pr[N],sta[N],top,j,kc,ul[N];
long double ans,k[N],b[N],l[N],r[N];
long long s;
int tree[N*2];
struct str{
	long double s;
	int x,t;
}e[N*2];
struct scc{
	int x,t;
	bool operator <(const scc &a) const
	{
		return a.x>x;
	}
};
set<scc> w;
bool cmp(str a,str b)
{
	return a.s<b.s;
}
void modify(int n,int i,int x)
{
	while(i<=n)
	{
		tree[i]+=x;
		i+=-i&i;
	}
}
long long Query(int i)
{
	int s=0;
	while(i)
	{
		s+=tree[i];
		i-=-i&i;
	}
	return s;
}
bool check(long double R)
{
	int i;
	long long s=0;
	kc=0;
	for(i=1;i<=n;++i)
	{
		long double u=k[i]*k[i]+1,v=k[i]*b[i]*2,w=b[i]*b[i]-R*R;
		if(v*v-4*u*w>0)
		{
			long double a=(-v+sqrt(v*v-4*u*w))/2/u,c=(-v-sqrt(v*v-4*u*w))/2/u;
			long double d=k[i]*a+b[i],f=k[i]*c+b[i];
			l[i]=atan2(d,a),r[i]=atan2(f,c);
			if(r[i]<l[i])
				swap(l[i],r[i]);
			e[++kc]=(str){l[i],i,0};
			e[++kc]=(str){r[i],i,1};
		}
	}
	sort(e+1,e+1+kc,cmp);
	memset(tree,0,sizeof(tree));
	for(i=1;i<=kc;++i)
		if(e[i].t==0)
		{
			ul[e[i].x]=i;
			modify(kc,i,1);
		}
		else
		{
			s+=Query(kc)-Query(ul[e[i].x]);
			--top;
			modify(kc,ul[e[i].x],-1);
		}
	return (s>=m);
}
int main()
{
	scanf("%d %d %d %d",&n,&p,&q,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&x[i],&y[i]);
		k[i]=x[i]/1000.0;
		b[i]=y[i]/1000.0-q/1000.0+k[i]*p/1000.0;
	}
	long double l=0,r=1000000000000.0;
	while(r-l>0.000000001)
	{
		long double mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	check(l);
	for(i=1;i<=kc;++i)
		if(e[i].t==0)
		{
			w.insert((scc){i,e[i].x});
			ul[e[i].x]=i;
		}
		else
		{
			auto tmp=w.find((scc){ul[e[i].x],e[i].x});
			auto it=tmp;
			for(++it;it!=w.end();++it)
			{
				long double x=(b[e[i].x]-b[it->t])/(k[it->t]-k[e[i].x]);
				long double y=k[e[i].x]*x+b[e[i].x];
				ans+=sqrt(x*x+y*y);
				++s;
			}
			w.erase(tmp);
		}
	ans+=(m-s)*l;
	printf("%.12LF\n",ans);
}