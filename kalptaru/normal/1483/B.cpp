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
		int n;
		cin>>n;
		ll a[n];
		int next[n];
		int jump[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			next[i]=(i+1)%n;
			jump[i]=i;
		}
		int i=0;
		vector<int> ans;
		int t=n;
		int p=0;
		while(0<t)
		{
			// cout<<i<<' ';
			i=jump[i];

			if(__gcd(a[i],a[next[i]])==1)
			{
				ans.pb(next[i]+1);
				if(jump[next[i]]==next[i])
				{
					t--;
				}
				else
				{
					jump[next[next[i]]]=jump[next[i]];
				}
				next[i]=next[next[i]];
				i=next[i];
				p=i;
			}
			else
			{
				jump[p]=jump[next[i]];
				t--;
				i=next[i];
			}
		}
		// cout<<"---\n";
		cout<<ans.size();
		FOR(j,0,ans.size())
		{
			cout<<' '<<ans[j];
		}

		cout<<'\n';
	}
	return 0;
}