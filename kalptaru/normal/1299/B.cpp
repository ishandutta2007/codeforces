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
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll x[n],y[n];
		FOR(i,0,n)
		{
			cin>>x[i]>>y[i];
		}
		if(n%2==1)
		{
			cout<<"no";
			return 0;
		}
		n/=2;
		bool f=1;
		FOR(i,1,n)
		{
			if(((x[i]-x[i-1])!=(x[n+i-1]-x[n+i]))||((y[i]-y[i-1])!=(y[n+i-1]-y[n+i])))
			{
				f=0;
				break;
			}
		}
		if(((x[2*n-1]-x[0])!=(x[n]-x[n-1]))||((y[2*n-1]-y[0])!=(y[n]-y[n-1])))
		f=0;
		if(f)
		{
			cout<<"yes";
		}
		else
		{
			cout<<"NO";
		}
	}
	return 0;
}