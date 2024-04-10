#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[1001000];
int a[1001000];
int f[1001000];
int cnt[1001000];
int ans[1001000];
struct query
{
	int l,k,ind;
	query(int _l,int _k,int _ind)
	{
		l=_l;
		k=_k;
		ind=_ind;
	}
};
vector<query> qry[1001000];
vector<int> st[1001000];
void add(int x)
{
	f[cnt[x]]--;
	cnt[x]++;
	st[cnt[x]].pb(x);
//	f[cnt[x]]++;
}
void del(int x)
{
//	f[cnt[x]]--;
	cnt[x]--;
	st[cnt[x]].pb(x);
	f[cnt[x]]++;
}
	int n,q;
void dfs(int u,int fa)
{
	add(a[u]);
//	cerr<<u<<endl;
//	for(int i=1;i<=n;i++)
//		cerr<<f[i]<<" ";
//	cerr<<endl;
	for(query q:qry[u])
	{
		int l=q.l;
		int k=q.k;
		int lb=l,ub=n+1;
		while(lb<ub)
		{
			int mid=(lb+ub)/2;
			if(f[mid]-f[l-1]<k)
				lb=mid+1;
			else	ub=mid;
		}
		ans[q.ind]=-1;
		while(sz(st[lb]))
			if(cnt[st[lb].back()]==lb)
			{
				ans[q.ind]=st[lb].back();
				break;
			}
			else	st[lb].pop_back();
	}
	for(auto v:G[u]) if(v!=fa)
		dfs(v,u);
	del(a[u]);
}
void solve()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		f[i]=n;
		cnt[i]=0;
		qry[i].clear();
		st[i].clear();
	}
	f[0]=n;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=2;i<=n;i++)
	{
		int u;
		scanf("%d",&u);
		G[u].pb(i);
		G[i].pb(u);
	}
	for(int i=1;i<=q;i++)
	{
		int v,l,k;
		scanf("%d%d%d",&v,&l,&k);
		qry[v].pb(query(l,k,i));
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}