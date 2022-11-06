#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		map <ll,int> m;
		vector< pair<int,int> > ans;
		int cnt,j=1;
		FOR(i,0,n)
		{
			if(m[a[i]]==0)
			{
				m[a[i]]=1;	
			}
			else
			{
				ans.pb(mp(j,i+1));
				cnt++;
				m.clear();
				j=i+2;
			}
		}
		int o=ans.size();
		if(o==0)
		cout<<-1;
		else
		{
			ans[o-1].second=n;
			cout<<o<<'\n';
			FOR(i,0,o)
			{
				cout<<ans[i].first<<' '<<ans[i].second<<'\n';
			}
		}
	}
	return 0;
}