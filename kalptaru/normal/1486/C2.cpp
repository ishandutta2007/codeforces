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
const ll mod=1000000007;
ll INF=1e18;
ll po(ll a,ll b){
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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	// #ifndef ONLINE_JUDGE
	// freopen("INPUT.txt", "r", stdin);
	// freopen("OUTPUT.txt", "w", stdout);
	// #endif
	ll test=1;
	// cin>>test;
	while(test--)
	{
		int l=1,r,p,x;
		int ans;
		cin>>r;
		cout<<"? 1 "<<r<<"\n";
		cin>>p;
		while((r-l)>2)
		{
			// cout<<l<<'_'<<r<<"----"<<p<<'\n';
			int mid=(l+r)/2;
			if(p>mid)
			{
				cout<<"? "<<mid+1<<' '<<max(r,p)<<'\n';
				cin>>x;
				if(x==p)
				{
					l=mid+1;
				}
				else
				{
					r=mid;
				}

			}
			else
			{
				cout<<"? "<<min(l,p)<<" "<<mid<<'\n';
				cin>>x;
				if(x==p)
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}

		}
			
		if((r-l)==2)
		{
			cout<<"? "<<l<<' '<<l+1<<'\n';
			cin>>x;
			if(x==l)
			{
				cout<<"? "<<l+1<<' '<<r<<'\n';
				cin>>x;
				if(x==r)
				{
					ans=l+1;
				}
				else
				{
					ans=r;
				}
			}
			else
			{
				cout<<"? "<<l<<' '<<r<<'\n';
				cin>>x;
				if(x==l)
				{
					ans=r;
				}
				else
				{
					ans=l;
				}				
			}
		}
		else
		{
			cout<<"? "<<l<<' '<<r<<'\n';
			cin>>x;
			ans=l+r-x;
		}
		cout<<"! "<<ans<<'\n';

	}

	return 0;
}