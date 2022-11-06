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
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("G.in", "r", stdin);
    // freopen("equal.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		int x,y,ans=0;
		int en[2*n];
		FOR(i,0,2*n)
		{
			en[i]=-1;
		}
		FOR(i,0,k)
		{
			cin>>x>>y;
			if(x>y)
				swap(x,y);
			x--;
			y--;
			en[x]=i;
			en[y]=i;
			bool in[i+1]={0};
			int a=0;
			FOR(j,x+1,y)
			{
				if(en[j]==-1)
					continue;
				if(in[en[j]])
				{
					a--;
				}
				else
				{
					a++;
				}
				in[en[j]]=!in[en[j]];
			}
			ans+=a;
		}
		vector<int> lef;
		FOR(i,0,2*n)
		{
			if(en[i]==-1)
			{
				lef.pb(i);
			}
		}
		int o=n-k;
		FOR(i,0,o)
		{
			x=lef[i];
			y=lef[i+o];
			en[x]=i+k;
			en[y]=i+k;
			bool in[i+k+1]={0};
			int a=0;
			FOR(j,x+1,y)
			{
				if(en[j]==-1)
					continue;
				if(in[en[j]])
				{
					a--;
				}
				else
				{
					a++;
				}
				in[en[j]]=!in[en[j]];
			}
			ans+=a;
		}
		cout<<ans<<'\n';
	}
	return 0;
}