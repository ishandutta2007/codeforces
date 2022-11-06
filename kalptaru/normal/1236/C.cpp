#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll powm(ll a,ll b)
{
	ll r=a%mod,ans=1;
	while(b>0)
	{
		if(b%2==1)
		ans=(ans*r)%mod;
		r=(r*r)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		int ans[n][n];
		int k=n>>1;
		if(n%2==0)
		{
			FOR(i,0,n)
			{
				FOR(j,0,k)
				{
					cout<<i*k+j+1<<' ';
				}
				FOR(j,0,k)
				{
					cout<<n*n-i*k-k+j+1<<' ';
				}
				cout<<'\n';
			}
		}
		else
		{
			FOR(i,0,n)
			{
				FOR(j,0,k)
				ans[i][j]=i*k+j+1;
			}
			FOR(i,0,n)
			{
				ans[n-i-1][k]=k*n+i+1;
			}
			FOR(i,0,n)
			{
				FOR(j,0,k)
				ans[i][n-j-1]=n*n-i*k-j;
			}
			FOR(i,0,n)
			{
				FOR(j,0,n)
				cout<<ans[i][j]<<' ';
				cout<<'\n';
			}
		}
	}
	return 0;
}