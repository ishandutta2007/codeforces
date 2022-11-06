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
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		int k=n,t=-1;
		FOR(i,0,n)
		{
			if(a[i]<i)
			{
				k=i-1;
				break;
			}
		}
		FOR(i,0,n)
		{
			if(a[n-i-1]<i)
			{
				t=(n-i);
				break;
			}
		}
		if(k>=t)
		{
			cout<<"YES"<<'\n';
		}
		else
		{
			cout<<"NO"<<'\n';
		}
	}
	return 0;
}