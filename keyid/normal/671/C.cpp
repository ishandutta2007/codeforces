#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second

typedef long long LL;
typedef pair <int,int> pii;
typedef map <int,int> :: iterator mpi;

const int MAXN=200005;

vector <int> f[MAXN],p[MAXN];
map <int,int> s;
LL cnt[MAXN];

int main()
{
	for (int i=1;i<=200000;i++)
		for (int j=i;j<=200000;j+=i)
			f[j].pb(i);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		for (int j=0;j<f[a].size();j++)
			p[f[a][j]].pb(i);
	}
	LL now=0;
	for (int i=1;i<=n;i++)
	{
		s[i]=i;
		now+=i;
	}
	for (int i=200000;i>=0;i--)
	{
		cnt[i]=(LL)n*(n+1)-now;
		if (p[i].size()<2) continue;
		pii e1(p[i][0],p[i][p[i].size()-2]),e2(p[i][1],p[i][p[i].size()-1]);
		int lst=0;
		for (mpi j=s.begin();j!=s.end();)
		{
			int x=j->fi,y=j->sc;
			if (y>=e1.sc) break;
			now-=(LL)(min(e1.fi,x)-lst)*y;
			lst=x;
			if (x>e1.fi) break;
			s.erase(j++);
		}
		if (lst)
		{
			now+=(LL)min(lst,e1.fi)*e1.sc;
			s[min(lst,e1.fi)]=e1.sc;
		}
		if (s.find(e1.fi)==s.end())
			s[e1.fi]=s.upper_bound(e1.fi)->sc;
		lst=e1.fi;
		for (mpi j=s.upper_bound(e1.fi);j!=s.end();)
		{
			int x=j->fi,y=j->sc;
			if (y>=e2.sc) break;
			now-=(LL)(min(x,e2.fi)-lst)*y;
			lst=x;
			if (x>e2.fi) break;
			s.erase(j++);
		}
		if (lst>e1.fi)
		{
			now+=(LL)(min(lst,e2.fi)-e1.fi)*e2.sc;
			s[min(lst,e2.fi)]=e2.sc;
		}
		if (s.find(e2.fi)==s.end())
			s[e2.fi]=s.upper_bound(e2.fi)->sc;
		lst=e2.fi;
		for (mpi j=s.upper_bound(e2.fi);j!=s.end();)
		{
			int x=j->fi,y=j->sc;
			now-=(LL)(x-lst)*y;
			lst=x;
			s.erase(j++);
		}
		if (lst>e2.fi)
		{
			s[n]=n+1;
			now+=(LL)(n-e2.fi)*(n+1);
		}
	}
	LL ans=0;
	for (int i=1;i<=200000;i++)
		ans+=i*(cnt[i]-cnt[i-1]);;
	printf("%lld",ans);
	return 0;
}