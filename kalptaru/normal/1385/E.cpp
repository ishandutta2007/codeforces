#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		bool f=1;
		vector<int> gra[n];
		vector<int> topo;
		vector<pair<int, int > > und,dir;
		int t,x,y;
		int co[n]={0};
		FOR(i,0,m)
		{
			cin>>t>>x>>y;
			x--;
			y--;
			if(t==0)
			{
				und.pb(mp(x,y));
			}
			else
			{
				dir.pb(mp(x,y));
				gra[x].pb(y);
				co[y]++;
			}
		}
		set<pair<int,int> > fuc;
		pair<int,int> nod;
		FOR(i,0,n)
		{
			fuc.insert(mp(co[i],i));
		}
		FOR(i,0,n)
		{
			nod=*fuc.begin();
			fuc.erase(nod);
//			cout<<nod.second<<' ';
			if(nod.first!=0)
			{
//				cout<<nod.first<<'k';
				f=0;
				break;
			}
			int u=nod.second;
			FOR(j,0,gra[u].size())
			{
				fuc.erase(mp(co[gra[u][j]],gra[u][j]));
				co[gra[u][j]]--;
				fuc.insert(mp(co[gra[u][j]],gra[u][j]));
			}
			topo.pb(nod.second);
		}
		if(f==0)
		{
			cout<<"NO\n";
			continue;
		}
		int ind[n];
		FOR(i,0,n)
		{
			ind[topo[i]]=i;
		}
		cout<<"YES\n";
		FOR(i,0,dir.size())
		{
			cout<<dir[i].first+1<<' '<<dir[i].second+1<<'\n';
		}
		FOR(i,0,und.size())
		{
			if(ind[und[i].first]<ind[und[i].second])
			{
				cout<<und[i].first+1<<' '<<und[i].second+1<<'\n';
			}
			else
			{
				cout<<und[i].second+1<<' '<<und[i].first+1<<'\n';
			}
		}
	}
	return 0;
}