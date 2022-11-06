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
		int n,x,y;
		cin>>n>>x>>y;
		int b[n];
		int cnt[n+1]={0};
		vector<int> ind[n+1];
		int u[n+1]={0};
		int m=0,mi=-1;
		FOR(i,0,n)
		{
			cin>>b[i];
			b[i]--;
			cnt[b[i]]++;
			ind[b[i]].pb(i);
		}
		set<pair<int,int> > el,fl;
		pair<int,int> e,k;
		int go;
		FOR(i,0,n+1)
		{
			if(cnt[i]==0)
			{
				go=i;
			}
			else
			{
				el.insert(mp(cnt[i],i));
			}
		}
		int ans[n];
		memset(ans,-1,sizeof(ans));
		FOR(i,0,x)
		{
			e=*(--el.end());
			ans[ind[e.second][u[e.second]]]=e.second;
			u[e.second]++;
			el.erase(mp(cnt[e.second],e.second));
			cnt[e.second]--;
			if(cnt[e.second]>0)
			el.insert(mp(cnt[e.second],e.second));
		}
//		FOR(i,0,n)
//		{
//			cout<<ans[i]+1<<' ';
//		}
//		cout<<'\n';
		int cn[n+1]={0};
		FOR(i,0,(y-x))
		{
			e=*(el.begin());
			cn[e.second]++;
			el.erase(e);
			e.first--;
			if(e.first>0)
			el.insert(e);
		}
//		cout<<'k';
//		cn[go]+=(n-y);
		el.clear();
		FOR(i,0,n+1)
		{
			if(cn[i]>0)
			{
//				cout<<i<<' '<<cn[i]<<'\n';
				el.insert(mp(cn[i],i));
			}
			if(cnt[i]>0)
			{
				fl.insert(mp(i,cnt[i]));
			}
		}
//		cout<<'l';
		bool pos=1;
		while(!el.empty())
		{
			e=*(--el.end());
			el.erase(e);
//			cout<<e.second<<"P ";
			while(e.first>0)
			{
				if(fl.upper_bound(mp(e.second,n))==fl.end())
				{
					k=*fl.begin();
				}
				else
				{
					k=*fl.upper_bound(mp(e.second,n));
				}
				fl.erase(k);
				if(k.first==e.second)
				{
					pos=0;
					break;
				}
				if(k.second<=e.first)
				{
					e.first-=k.second;
					FOR(i,0,k.second)
					{
						ans[ind[k.first][u[k.first]]]=e.second;
						u[k.first]++;
					}
				}
				else
				{
					k.second-=e.first;
					FOR(i,0,e.first)
					{
						ans[ind[k.first][u[k.first]]]=e.second;
						u[k.first]++;
					}
					fl.insert(k);
					e.first=0;
				}
			}
			if(pos==0)
			break;
		}
//		cout<<'l';
		while(! fl.empty())
		{
			k=*fl.begin();
			fl.erase(k);
			FOR(i,0,k.second)
			{
				ans[ind[k.first][u[k.first]]]=go;
				u[k.first]++;
			}
		}
		if(pos==0)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			FOR(i,0,n)
			{
				cout<<ans[i]+1<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}