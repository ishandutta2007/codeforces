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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ind=-1,in=-1;
		bool f=1;
		FOR(i,0,n)
		{
			if(s[i]=='1')
			{
				if(f)
				{
					in=i;
					f=0;
				}
				ind =i;
				
			 } 
		}
		if(f)
		cout<<n<<'\n';
		else
		{
			cout<<2*max(n-in,ind+1)<<'\n';
		}
	}
	return 0;
}