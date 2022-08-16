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

const int maxn = 2e5+10;
const ll mod = 1e9+7;

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
ll fact[maxn],invfact[maxn];
void pre()
{
	fact[0] = invfact[0] = 1;
    for(int i = 1;i<maxn;i++)
    {
    	fact[i] = (fact[i-1]*i)%mod;
    	invfact[i] = inv(fact[i]);
    }
}
ll nCr(int n,int r)
{
	return (fact[n]*((invfact[r]*invfact[n-r])%mod))%mod;
}
int main()
{
    pre();
    int n;
    cin>>n;
    cout<<((2*nCr(2*n-1,n-1)-n)%mod+mod)%mod;
    return 0;
}