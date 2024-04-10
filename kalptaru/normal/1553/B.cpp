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
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const int N=100005;
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
   
    
	ll test=1;
	// int gt=0;
	cin>>test;
	while(test--)
	{
		string s,t;
		int n,m;
		cin>>t>>s;
		n=s.size();
		m=t.size();
		bool a[m][n];
		memset(a,0,sizeof(a));
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				if((i+j)==m)
					break;
				if(t[i+j]!=s[j])
					break;
				a[i+j][j]=1;
			}
		}

		bool f=0;
		FOR(i,0,m)
		{
			if(a[i][n-1])
			{
				f=1;
				break;
			}
			FOR(j,0,n)
			{
				if((i+j)==m)
					break;
				if(t[i+j]!=s[n-j-1])
					break;

				if(a[i+j][n-j-1])
				{
					f=1;
					break;
				}
			}
			if(f) break;
		}
		if(f)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}