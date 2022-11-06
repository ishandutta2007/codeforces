#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
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
		int a;
		bool f=0;
		FOR(i,0,n)
		{
			cin>>a;
			if(a%2==0)
			{
				a=a/2;
			}
			else
			{
				if(f)
				{
					if(a<0)
					a--;
					a=a/2;
					f=0;
				}
				else
				{
					if(a>0)
					a++;
					a=a/2;
					f=1;
				}
			}
			cout<<a<<'\n';
		}	
	}
	return 0;
}