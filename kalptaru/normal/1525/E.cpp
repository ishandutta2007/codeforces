#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
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
struct rob
{
	int x;
	int i;
	char d;
};
bool che(rob a,rob b)
{
	return a.x<b.x;
}
const int N=1000005;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif

    // freopen("equal.in", "r", stdin);
    // freopen("equal.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	// cin>>test;
	while(test--)
	{
		ll n,m;
		cin>>n>>m;
		ll a[m][n];
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cin>>a[j][i];
			}
		}
		ll to=0,b=0,d=1;
		FOR(i,0,n)
		{
			d*=(i+1);
			d%=mod;
		}

		FOR(i,0,m)
		{
			sort(a[i],a[i]+n);
			b=1;
			FOR(j,0,n)
			{
				b*=(a[i][j]-j-1);
				b%=mod;
				// cout<<a[i][j]<<' ';
			}
			// cout<<'\n';
			to=(to+d-b+mod)%mod;
		}
		cout<<(to*po(d,mod-2))%mod;
	}

	return 0;
}