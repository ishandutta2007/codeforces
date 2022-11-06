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
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=985661441;
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
ll in[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
	ll test=1;
	// cin>>test;
	// spre
	while(test--)
	{
		ll n,m;
		ll k;
		cin>>n>>m>>k;
		bool f=0;
		if(n>m)
		{
			f=1;
			swap(n,m);
		}
		ll a[n],b[m];
		if(f)
		{
			FOR(i,0,m)
			{
				cin>>b[i];
			}
			FOR(i,0,n)
			{
				cin>>a[i];
			}
		}
		else
		{
			FOR(i,0,n)
			{
				cin>>a[i];
			}
			FOR(i,0,m)
			{

				cin>>b[i];
			}
		}
		ll cnt[m];
		FOR(i,0,m)
		{
			in[b[i]]=i+1;
			cnt[i]=n;
		}
		FOR(i,0,n)
		{
			if(in[a[i]]!=0)
			{
				cnt[(m+(in[a[i]]-1-i))%m]--;
				// t--;
			}
		}
		int j=n%m;
		ll t=cnt[0];
		int o=1;
		while(j!=0)
		{
			o++;
			t+=cnt[j];
			j=(j+n)%m;
		}
		ll ans=n*o*((k-1)/t);
		k=(k-1)%t+1;
		j=0;
		while(k>cnt[j])
		{
			k-=cnt[j];
			j=(j+n)%m;
			ans+=n;
		}
		// FOR(i,0,m)
		// {
		// 	cout<<cnt[i]<<' ';

		// }
		FOR(i,0,n)
		{
			if(a[i]!=b[(j+i)%m])
				k--;
			ans++;
			if(k==0)
				break;
		}
		cout<<ans;

	}
	return 0;
}