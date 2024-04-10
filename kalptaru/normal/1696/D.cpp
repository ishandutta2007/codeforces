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
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
typedef long double ld;
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
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
int ti[2000000],ta[2000000];
int a[400000];
void bd(int v,int tl,int tr)
{
	if(tl==tr)
	{
		ti[v]=a[tl];
		ta[v]=a[tl];
		return;
	}
	int tm=(tl+tr)/2;
		bd(2*v,tl,tm);
		bd(2*v+1,tm+1,tr);
	ta[v]=max(ta[2*v],ta[2*v+1]);
	ti[v]=min(ti[2*v],ti[2*v+1]);
}
int mi(int v,int tl,int tr,int l,int r)
{
	if(l>r)
	{
		return 10000000;
	}
	if(tl==l && tr==r)
	{
		return ti[v];
	}
	int tm=(tl+tr)/2;
	return min(mi(2*v,tl,tm,l,min(r,tm)),mi(2*v+1,tm+1,tr,max(l,tm+1),r));
}
int ma(int v,int tl,int tr,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(tl==l && tr==r)
	{
		return ta[v];
	}
	int tm=(tl+tr)/2;
	return max(ma(2*v,tl,tm,l,min(r,tm)),ma(2*v+1,tm+1,tr,max(l,tm+1),r));
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
    while(test--)
    {
        int n;
        cin>>n;
        int nl[n],ng[n];
        FOR(i,0,n)
        {
        	cin>>a[i];
        	nl[i]=n-1;
        	ng[i]=n-1;
        }
        bd(1,0,n-1);
        stack<int> x,y;
        // break;
        FOR(i,0,n)
        {
        	while(!x.empty() && a[x.top()]<a[i])
        	{
        		ng[x.top()]=i;
        		x.pop();
        	}
        	x.push(i);
        	while(!y.empty() && a[y.top()]>a[i])
        	{
        		nl[y.top()]=i;
        		y.pop();
        	}
        	y.push(i);
        }
        int c=0;
        int i=0,o;
        // cout<<'p';
        // break;
        while(i<n-1)
        {
        	if(a[i]>a[i+1])
        	{
        		o=mi(1,0,n-1,i,ng[i]);
        	}
        	else
        	{
        		o=ma(1,0,n-1,i,nl[i]);
        	}
        	while(a[i]!=o)
        	{
        		i++;
        	}
        	c++;
        }
        cout<<c<<'\n';
    }
    return 0;
}