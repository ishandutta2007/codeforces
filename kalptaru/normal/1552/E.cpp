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
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
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
    // freopen("G.in", "r", stdin);
    // freopen("equal.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	// cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		int a[n*k];
		FOR(i,0,n*k)
		{
			cin>>a[i];
			a[i]--;
		}
		int re=ceil(n/(k-1));
		pair<int,int> ans[n];
		FOR(i,0,n)
		{
			ans[i].ff=-1;
		}
		FOR(i,0,re+1)
		{
			int l=i*(k-1),r=l+k-1;
			int last[n];
			FOR(j,0,n)
			{
				last[j]=-1;
			}
			FOR(j,0,n*k)
			{
				if(a[j]>=l && a[j]<r && ans[a[j]].ff==-1)
				{
					if(last[a[j]]!=-1)
					{
						ans[a[j]].ff=last[a[j]]+1;
						ans[a[j]].ss=j+1;
						FOR(z,0,n)
						{
							last[z]=-1;
						}
					}
					else
					{
						last[a[j]]=j;
					}
				}
			}
		}
		FOR(i,0,n)
		{
			cout<<ans[i].ff<<' '<<ans[i].ss<<'\n';
		}
	}
	return 0;
}