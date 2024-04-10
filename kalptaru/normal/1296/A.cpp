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
ll m1=1000000007;
ll m2=67280421310721;
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
		ll s=0;
		bool f=0,g=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			if(a[i]%2==0)
			f=1;
			else
			g=1;
			s+=a[i];
		}
		if((f && g) || s%2==1)
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