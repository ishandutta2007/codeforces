#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
		}
		a=(a*a);
		b>>=1;
	}
	return re;
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,k,x,si;
		cin>>n;
		vector<pair<int,int> > p;
		string t[n];
		int m=0;
		FOR(i,0,n)
		{
			cin>>t[i];
			cin>>k;
			si=t[i].size();
			FOR(j,0,k)
			{
				cin>>x;
				m=max(m,(x+si-1));
				p.pb(mp(x-1,i));
			}
		}
		char ans[m+10];
//		FOR(i,0,p.size())
//		cout<<p[i].first<<' ';
//		cout<<'\n';
		sort(p.begin(),p.end());
//		FOR(i,0,p.size())
//		cout<<p[i].first<<' ';
//		cout<<'\n';
		int i=0;
		FOR(j,0,p.size())
		{
			if(p[j].first==i )
			{
				si=t[p[j].second].size();
				FOR(k,0,si)
				{
					ans[i]=t[p[j].second][k];
					i++;
				}
			}
			else if(p[j].first>i)
			{
				ans[i]='a';
				j--;
				i++;
			}
			else
			{
				FOR(k,(i-p[j].first),t[p[j].second].size())
				{
					ans[i]=t[p[j].second][k];
					i++;
				}
			}
			if(i==m)
			break;
		}
		FOR(i,0,m)
		cout<<ans[i];
	}
	return 0;
}