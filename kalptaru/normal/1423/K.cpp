#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e9;
struct node
{
	int l=-1,r=-1;
	int z=0,o=0;
};
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
int an[1000005];
bool pr[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	cin>>test;
	an[1]=1;
	pr[1]=1;
	FOR(i,2,1000003)
	{
		if(pr[i]==0)
		{
			an[i]++;
			ll k=i;
			if((k*k)<1000003)
			{
				an[k*k]--;
			}
			for(int j=2*i;j<1000003;j+=i)
			{
				pr[j]=1;
			}
		}
	}
	FOR(i,1,1000003)
	{
		an[i]+=an[i-1];
	}
	while(test--)
	{
		int n;
		cin>>n;
		cout<<an[n]<<'\n';
	}
	return 0;
}