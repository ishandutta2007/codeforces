#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
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
int n,m;
string s[55];
bool vi[55][55];
bool che(int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=m)
	return 1;
	if(s[i][j]=='B')
	return 1;
	if(s[i][j]=='G')
	return 0;
	s[i][j]='#';
	return 1;
}
void dfs(int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=m)
	return;
	if(s[i][j]=='#')
	return;
	if(vi[i][j]==1)
	return;
	vi[i][j]=1;
	dfs(i-1,j);
	dfs(i+1,j);
	dfs(i,j-1);
	dfs(i,j+1);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		if(n==1)
		{
			cout<<a[0];
			return 0;
		}
		if(n==2)
		{
			cout<<(a[0]|a[1]);
			return 0;
		}
		ll o,m=0;
		FOR(i,0,n)
		{
			FOR(j,i+1,n)
			{
				FOR(k,j+1,n)
				{
					o=(a[i]|a[j]|a[k]);
					m=max(m,o);
				}
			}
		}
		cout<<m;
	}
	return 0;
}