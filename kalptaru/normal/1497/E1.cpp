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
bool che[10000005];
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
	cin>>test;
	// spre
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		ll a[n],b[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			b[i]=1;
			for(int j=2;j<220;j++)
			{
				while((a[i]%(j*j))==0)
				{
					a[i]/=(j*j);
				}
				if((a[i]%j)==0)
				{
					b[i]*=j;
					a[i]/=j;
				}
				if(a[i]==1)
				{
					break;
				}
			}
			if(a[i]!=1)
			{
				int o=sqrt(a[i]);
				if(a[i]!=(o*o))
				{
					b[i]*=a[i];
					a[i]=1;
				}
			}
		}
		int ans=1,p=0;
		FOR(i,0,n)
		{
			if(che[b[i]])
			{
				FOR(j,p,i)
				{
					che[b[j]]=0;
				}
				p=i;
				ans++;
				// cout<<b[i]<<' '<<i<<'\n';
			}
			che[b[i]]=1;
		}
		FOR(i,p,n)
		{
			che[b[i]]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}