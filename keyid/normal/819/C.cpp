#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;
typedef map <int,int> :: iterator msit;

#define pb push_back
#define fi first
#define sc second

const int MAXN=1000005;

LL N,M;
bool vis[MAXN];
vector <int> fac[MAXN];
vector <pii> sfac;
vector <LL> nfac;
LL ans;

LL get_pow(int a,int x)
{
	LL ret=1;
	while (x--)
		ret*=a;
	return ret;
}

void preprocess(int n)
{
	for (int i=2;i<=n;i++)
		if (!vis[i])
			for (int j=i;j<=n;j+=i)
			{
				vis[j]=true;
				fac[j].pb(i);
			}
}

void dfs1(int cur,LL now)
{
	if (cur>=sfac.size())
	{
		ans++;
		return;
	}
	for (int i=0;i<=sfac[cur].sc;i++)
	{
		dfs1(cur+1,now);
		now*=sfac[cur].fi;
		if (now>N)
			return;
	}
}

void dfs2(int cur,int sgn,LL now)
{
	if (cur>=nfac.size())
	{
		ans+=M/now*sgn;
		return;
	}
	dfs2(cur+1,sgn,now);
	dfs2(cur+1,-sgn,now*nfac[cur]);
}

void solve()
{
	int n[3],m[3],s[3];
	for (int i=0;i<3;i++)
		scanf("%d",&n[i]);
	N=1;
	for (int i=0;i<3;i++)
		N*=n[i];
	for (int i=0;i<3;i++)
		scanf("%d",&m[i]);
	M=1;
	for (int i=0;i<3;i++)
		M*=m[i];
	for (int i=0;i<3;i++)
		scanf("%d",&s[i]);
	map <int,int> f;
	for (int i=0;i<3;i++)
	{
		int x=s[i];
		for (int j=0;j<fac[s[i]].size();j++)
		{
			int d=fac[s[i]][j];
			while (x%d==0)
			{
				x/=d;
				f[d]++;
			}
		}
	}
	f[2]++;
	sfac.clear();
	for (msit it=f.begin();it!=f.end();++it)
		sfac.pb(*it);
	ans=0;
	dfs1(0,1);
	map <int,int> f2;
	for (int i=0;i<3;i++)
	{
		int x=n[i];
		for (int j=0;j<fac[n[i]].size();j++)
		{
			int d=fac[n[i]][j];
			while (x%d==0)
			{
				x/=d;
				f2[d]++;
			}
		}
	}
	nfac.clear();
	for (msit it=f2.begin();it!=f2.end();++it)
	{
		int d=it->fi;
		if (f[d]<it->sc)
			nfac.pb(get_pow(d,f[d]+1));
	}
	dfs2(0,1,1);
	printf("%lld\n",ans);
}

int main()
{
	preprocess(1000000);
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}