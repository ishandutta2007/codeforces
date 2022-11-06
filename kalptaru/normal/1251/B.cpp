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
	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		string s;
		int o=0,e=0,g=0,h=0;
		FOR(i,0,n)
		{
			cin>>s;
			int m=s.size();
			if(m%2==0)
			e++;
			else
			o++;
			FOR(i,0,m)
			{
				if(s[i]=='0')
				g++;
				else
				h++;
			}
		}
		if(o==0 && g%2==1) 
		{
			cout<<n-1<<'\n';
		}
		else
		{
			cout<<n<<'\n';
		}
	}
	return 0;
}