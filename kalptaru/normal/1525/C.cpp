#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp pop_back()
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
struct rob
{
	int x;
	int i;
	char d;
};
bool che(rob a,rob b)
{
	return a.x<b.x;
}
const int N=1000005;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif

    // freopen("equal.in", "r", stdin);
    // freopen("equal.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		rob a[n];
		int ans[n];
		FOR(i,0,n)
			cin>>a[i].x;
		FOR(i,0,n)
		{
			cin>>a[i].d;
			a[i].i=i;
			ans[i]=-1;
		}
		sort(a,a+n,che);
		vector<pair<int,int> > o;
		int c=-1,t;
		FOR(i,0,n)
		{
			if((a[i].x%2)==0)
			{
				if(a[i].d=='L')
				{
					if(c<0)
					{
						o.pb(mp(-a[i].x,a[i].i));
						c++;
					}
					else
					{
						t=(a[i].x-o[c].ff)/2;
						ans[a[i].i]=t;
						ans[o[c].ss]=t;
						o.pp;
						c--;
					}
				}
				else
				{
					o.pb(mp(a[i].x,a[i].i));
					c++;
				}
			}
		}
		while(c>0)
		{
			t=(2*m-o[c].ff-o[c-1].ff)/2;
			ans[o[c].ss]=t;
			ans[o[c-1].ss]=t;
			c-=2;
		}
		c=-1;
		o.clear();
		FOR(i,0,n)
		{
			if((a[i].x%2)==1)
			{
				if(a[i].d=='L')
				{
					if(c<0)
					{
						o.pb(mp(-a[i].x,a[i].i));
						c++;
					}
					else
					{
						t=(a[i].x-o[c].ff)/2;
						ans[a[i].i]=t;
						ans[o[c].ss]=t;
						o.pp;
						c--;
					}
				}
				else
				{
					o.pb(mp(a[i].x,a[i].i));
					c++;
				}
			}
		}
		while(c>0)
		{
			t=(2*m-o[c].ff-o[c-1].ff)/2;
			ans[o[c].ss]=t;
			ans[o[c-1].ss]=t;
			c-=2;
		}
		FOR(i,0,n)
		{
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}

	return 0;
}