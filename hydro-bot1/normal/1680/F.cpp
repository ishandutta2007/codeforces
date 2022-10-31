// Hydro submission #62c6734b8672efa577bf9d4a@1657172812779
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(s) (s).begin(),(s).end()
#define repd(i,n) for(int i=n-1;i>=0;--i)
#define forr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define forn(i,p,n) for(int i=p;i<=n;++i)
#define ford(i,p,n) for(int i=n;i>=p;--i)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)
#define INF 0x7f7f7f7f
#define PI acos(-1)
string int_to_string(ll n)
{
	string s="";
	while(n)
	{
		ll now=n%10;
		s+=now+'0';
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
ll string_to_int(string s)
{
	ll n=0;
	rep(i,s.size())
	{
		n*=10;
		n+=s[i]-'0';
	}
	return n;
}
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
const int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
const int MAXN=1e6+10;
int n,m;
vi v[MAXN];
bool use[MAXN];
int c[MAXN];
int d1[MAXN],d2[MAXN];
int sum[MAXN];
int dep[MAXN];
int all;
void print()
{
	cout<<"YES"<<endl;
	forn(i,1,n)
	{
		cout<<c[i];
	}
	cout<<endl;
}
void dfs1(int now,int fa,int col)
{
	c[now]=col;
	use[now]=1;
	dep[now]=dep[fa]+1;
	rep(i,v[now].size())
	{
		int u=v[now][i];
		if(u==fa)
		{
			continue;
		}
		if(use[u])
		{
			if(dep[u]<dep[now])
			{
				if(c[u]==c[now])
				{
					all++;
					sum[u]++;
					d1[now]++;
					d1[u]--;
				}
				else
				{
					d2[now]++;
					d2[u]--;
				}
			}
			continue;
		}
		dfs1(u,now,col^1);
	}	
}
void dfs2(int now,int fa)
{
	use[now]=1;
	rep(i,v[now].size())
	{
		int u=v[now][i];
		if(u==fa)
		{
			continue;
		}
		if(use[u])
		{
			continue;
		}
		dfs2(u,now);
		sum[now]+=sum[u];
		d1[now]+=d1[u];
		d2[now]+=d2[u];
	}
}
void upd(int now,int fa)
{
	c[now]^=1;
	use[now]=1;
	rep(i,v[now].size())
	{
		int u=v[now][i];
		if(u==fa)
		{
			continue;
		}
		if(use[u])
		{
			continue;
		}
		upd(u,now);
	}
}
bool dfs3(int now,int fa)
{
	use[now]=1;
	rep(i,v[now].size())
	{
		int u=v[now][i];
		if(u==fa)
		{
			continue;
		}
		if(use[u])
		{
			continue;
		}
		if(d2[u]==0&&sum[u]==0&&d1[u]==all)
		{
			upd(u,now);
			if(c[u]==0&&c[now]==0)
			{
				forn(i,1,n)
				{
					use[i]=0;
				}
				upd(1,0);
			}
			print();
			return 1;
		}
		if(dfs3(u,now))
		{
			return 1;
		}
	}
	return 0;
}
void init()
{
	forn(i,1,n)
	{
		v[i].clear();
	}
	forn(i,1,n)
	{
		use[i]=0;
	}
	forn(i,1,n)
	{
		d1[i]=0;
		d2[i]=0;
		sum[i]=0;
	}
	all=0;
}
void output(string s,int a[])
{
	cout<<s<<endl;
	forn(i,1,n)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void solve()
{
	cin>>n>>m;
	init();
	forn(i,1,m)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	forn(i,1,n)
	{
		use[i]=0;
	}
	dfs1(1,0,0);
	forn(i,1,n)
	{
		use[i]=0;
	}
	dfs2(1,0);
	if(all<=1)
	{
		forn(i,1,n)
		{
			rep(j,v[i].size())
			{
				int u=v[i][j];
				if(c[u]==0&&c[i]==0)
				{
					forn(i,1,n)
					{
						use[i]=0;
					}
					upd(1,0);
					print();
					return;
				}
			}
		}
		print();
		return;
	}
	forn(i,1,n)
	{
		use[i]=0;
	}
	if(!dfs3(1,0))
	{
		cout<<"NO"<<endl;
	}
}
signed main()
{
    cin.tie(0);
    cout.tie(0);
	std::ios::sync_with_stdio(false);
  	int TEST_CASE;
	cin>>TEST_CASE;
  	while(TEST_CASE--)
  	{
  		solve();
  	}
  	return 0;
}