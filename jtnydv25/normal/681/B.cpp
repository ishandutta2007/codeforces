#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC

const int maxn = 1e6+10;
ll mod = 1e9+7;

ll powr(ll a, ll b)
{
	ll x = 1%mod;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a)
{
	return powr(a,mod-2);
}

void pre()
{
    
}
int main()
{
    pre();
    ll a = 1234567,b=123456,c=1234,n,tot_a=1224720;
    mod = a;
    cin>>n;
    bool found = false;
    ll _inv = powr(b,tot_a-1);
    for(ll z = 0;z*c<=n;z++)
    {
    	// a*x + b* y = n - c*z;

    	ll m = n - c*z;

    	ll y = (m*_inv)%a;

    	if(m >= b*y){
    		// cout<<z<<endl;
    		found = true;
    		break;
    	}
    }
    cout<<(found?"YES":"NO");
}