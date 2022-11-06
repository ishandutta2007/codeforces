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
// ll mod=8589934592;
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
	ll test=1;
	cin>>test;
	FOR(gtest,0,test)
	{
		int n;
		cin>>n;
		// n=gtest;
		bool c[n]={0};
		c[0]=1;
		// c[1]=1;
		c[n-1]=1;
		double o=n,p;
		while(o>2)
		{
			p=ceil(sqrt(o));
			// cout<<p<<' '<<ceil(o/p)<<'\n';
			c[int(p-1)]=1;
			o=p;
		}
		cout<<n+5<<'\n';
		// cout<<'\n';
		int cn=n+5;
		FOR(i,0,n)
		{
			if(c[i]==0)
			{
				cn--;
				cout<<i+1<<' '<<n<<'\n';
			}
		}
		o=n;
		while(o>2)
		{
			p=ceil(sqrt(o));
			cout<<o<<' '<<p<<'\n';
			cout<<o<<' '<<p<<'\n';
			o=p;
			cn-=2;
		}
		while(cn>0)
		{
			cn--;
			cout<<"1 2\n";
		}
		// cout<<'\n';
	}
	return 0;
}