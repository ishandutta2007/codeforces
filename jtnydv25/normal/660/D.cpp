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

pii points[2005];
map<pii,ll> myp;
ll C2(ll x)
{
	if(x==1)
		return 0;
	return (x*(x-1))/2;
}
int gc(int a,int b)
{
	if(a==0)
		return b;
	if(b == 0)
		return a;
	return __gcd(a,b);
}
int main()
{
	int n,x,y;
	cin>>n;
	for(int i = 0;i<n;i++)
		cin>>points[i].F>>points[i].S;
	ll cnt1 = 0,cnt2 = 0;
	for(int i = 0;i<n;i++)
		for(int j = i+1;j<n;j++)
		{
			int x1 = points[i].F+points[j].F,y1=points[i].S+points[j].S;
			myp[mp(x1,y1)]++;
		}
	ll ans = 0;	
	for(map<pii,ll>::iterator it = myp.begin();it!=myp.end();it++)
		ans+=C2(it->S);
	cout<<ans;		
}