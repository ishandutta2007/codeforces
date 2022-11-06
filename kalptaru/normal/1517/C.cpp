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
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
ll mod=1e9+7;
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
int ans[505][505];
int n;
int c,o;
void dfs(int i,int j)
{
	if(c==0)
		return;
	c--;
	ans[i][j]=o;
	if(c==0)
		return;
	if(ans[i][j-1]==0)
	{
		dfs(i,j-1);
	}
	if(c==0)
		return;
	if(ans[i+1][j]==0 && i<n)
	{
		dfs(i+1,j);
	}
	return;
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
    // ll gtest=0;
    // spre
	ll test=1;
	// cin>>test;
	while(test--)
	{
		cin>>n;
		int p[n];
		FOR(i,0,n)
		{
			cin>>p[i];
		}
		FOR(i,0,n+1)
		{
			ans[i][0]=ans[0][i]=n+1;
		}
		FOR(i,0,n)
		{
			o=p[i];
			c=p[i];
			dfs(i+1,i+1);	
		}
		FOR(i,0,n)
		{
			FOR(j,0,i+1)
			{
				cout<<ans[i+1][j+1]<<" ";
			}
			cout<<'\n';
		}
	}

	return 0;
}