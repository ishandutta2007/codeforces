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
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=998244353;
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
		int n,m;
		cin>>n>>m;
		int cnt[n+1]={0};
		int a[m][2];
		int k[m];
		bool f=0;
		int u=(m+1)/2;
		FOR(i,0,m)
		{
			cin>>k[i];
			cin>>a[i][0];
			FOR(j,1,k[i])
			{
				cin>>a[i][1];
			}
			if(k[i]==1)
			{
				cnt[a[i][0]]++;
				if(cnt[a[i][0]]>u)
				{
					f=1;
				}
			}
		}
		if(f)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		FOR(i,0,m)
		{
			if(k[i]>1)
			{
				if(cnt[a[i][0]]>cnt[a[i][1]])
				{
					swap(a[i][0],a[i][1]);
				}
				cnt[a[i][0]]++;
			}
			cout<<a[i][0]<<' ';
		}
		cout<<'\n';

	}
	return 0;
}