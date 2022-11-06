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
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[2*n];
		char c;
		FOR(i,0,2*n)
		{
			cin>>c;
			if(c=='+')
			{
				a[i]=-1;
			}
			else
			{
				cin>>a[i];
			}
		}
		set<int> s;
		int r;
		vector<int> ans;
		FORD(i,2*n,0)
		{
			if(a[i]==-1)
			{
				if(s.empty())
				{
					cout<<"NO";
					return 0;
				}
				r=*s.begin();
				ans.pb(r);
				s.erase(r);
			}
			else
			{
				if(s.empty())
				{
					s.insert(a[i]);
					continue;
				}
				r=*s.begin();
				if(r<a[i])
				{
					// cout<<r<<' '<<a[i];
					cout<<"NO";
					return 0;
				}
				s.insert(a[i]);
			}
		}
		cout<<"YES\n";
		FORD(i,n,0)
		{
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}