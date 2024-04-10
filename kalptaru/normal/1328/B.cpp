#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		ll n,k;
		cin>>n>>k;
		int i=1;
		for(;i<n;i++)
		{
			if(k<=i)
			{
				break;
			}
			k-=i;
		}
//		cout<<k<<'k'<<i;
		FOR(j,0,n-i-1)
		{
			cout<<'a';
		}
		cout<<'b';
		FOR(j,0,i-k)
		cout<<'a';
		cout<<'b';
		FOR(j,0,k-1)
		cout<<'a';
		cout<<'\n';
	}
	return 0;
}