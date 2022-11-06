#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
ll mod=1e9+7;
ll INF=1e18;
map<pair<ll,ll>,int> nodes;
bool vis[400005];
bool be[400005];
vector<pair<int,int> > ans;
int dfs(int i,vector<pair<int,int> > gra[],int ed)
{
	if(be[i])
	{
		return ed;
	}
	if(vis[i])
	{
		return -1;
	}
	vis[i]=1;
	be[i]=1;
	int o=-1,p;
	FOR(k,0,gra[i].size())
	{
		if(gra[i][k].ss!=ed)
		{
			p=dfs(gra[i][k].ff,gra,gra[i][k].ss);
			if(p!=-1)
			{
				if(o==-1)
				{
					o=p;
				}
				else
				{
					ans.pb(mp(o,p));
					o=-1;
				}
			}
		}
	}

	be[i]=0;
	if(o==-1)
	{
		return ed;
	}
	else if(ed!=-1)
	{
		ans.pb(mp(ed,o));
		return -1;
	}
	else
	{
		return o;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("java2016.in", "r", stdin);
    // freopen("java2016.out", "w", stdout);
    // ll gtest=0;
    // spre
	ll test=1;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a,b,c,d;
		pair<ll,ll> e,f;
		int u[n],v[n];
		int p=1;
		FOR(i,0,n)
		{
			cin>>a>>b>>c>>d;
			ll o=__gcd(((a+b)*d),(b*c));
			e=mp(((a+b)*d)/o,(b*c)/o);
			o=__gcd((a*d),(b*(c+d)));
			f=mp((a*d)/o,(b*(c+d))/o);
			if(nodes[e]==0)
			{
				nodes[e]=p;
				p++;
			}
			if(nodes[f]==0)
			{
				nodes[f]=p;
				p++;
			}
			u[i]=nodes[e];
			v[i]=nodes[f];
		}
		vector<pair<int,int> > gra[p];
		FOR(i,0,n)
		{
			gra[u[i]].pb(mp(v[i],i));
			gra[v[i]].pb(mp(u[i],i));
		}
		FOR(i,0,p)
		{
			// cout<<i<<'\n';
			// FOR(j,0,gra[i].size())
			// {
			// 	cout<<gra[i][j].ff<<' '<<gra[i][j].ss<<'\n';
			// }
			// cout<<'\n';
			if(vis[i]==0)
			{
				dfs(i,gra,-1);
			}
		}
		cout<<ans.size()<<'\n';
		FOR(i,0,ans.size())
		{
			cout<<ans[i].ff+1<<' '<<ans[i].ss+1<<'\n';
		}
	}
	return 0;
}