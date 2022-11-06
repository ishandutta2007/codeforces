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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
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
string s;
int n;
int dfs(int l,int r,int c)
{
	if(l==r)
	{
		if((s[l]-'a')==c)
		return 0;
		else
		return 1;
	}
	int mid=(l+r)/2;
	int rt=0,le=0;
	FOR(i,l,mid+1)
	{
		if((s[i]-'a')!=c)
		le++;
	}
	rt+=dfs(l,mid,c+1);
	FOR(i,mid+1,r+1)
	{
		if((s[i]-'a')!=c)
		rt++;
	}
	le+=dfs(mid+1,r,c+1);
	return(min(rt,le));
}
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		cin>>n;
		cin>>s;
		cout<<dfs(0,n-1,0)<<'\n';
	}
	return 0;
}