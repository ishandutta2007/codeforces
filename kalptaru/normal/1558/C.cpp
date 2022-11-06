#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const ll N=4000005;
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
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("azerah.in", "r", stdin);
    // freopen("azerah.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int p[n];
		bool f=0;
		FOR(i,0,n)
		{
			cin>>p[i];
		}
		FOR(i,0,n)
		{
			if((i%2)==(p[i]%2))
			{
				f=1;
				cout<<"-1\n";
				break;
			}
		}
		if(f)
		{
			continue;
		}
		vector<int> ans;
		for(int i=n/2;i>0;i--)
		{
			int o;
			for(int j=0;j<n;j+=2)
			{
				if(p[j]==(2*i+1))
				{
					o=j;
					break;
				}
			}
			ans.pb(o+1);
			FOR(j,0,o/2)
			{
				swap(p[j],p[o-j]);
			}
			for(int j=1;j<n;j+=2)
			{
				if(p[j]==(2*i))
				{
					o=j-1;
					break;
				}
			}
			ans.pb(o+1);
			FOR(j,0,o/2)
			{
				swap(p[j],p[o-j]);
			}
			o+=2;
			ans.pb(o+1);
			FOR(j,0,o/2)
			{
				swap(p[j],p[o-j]);
			}
			ans.pb(3);
			swap(p[0],p[2]);
			ans.pb(2*i+1);
			FOR(j,0,i)
			{
				swap(p[j],p[2*i-j]);
			}
		}
		cout<<ans.size()<<'\n';
		for(auto i: ans)
		{
			cout<<i<<' ';

		}
		cout<<'\n';
	}

	return 0;
}