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
		string s;
		int n;
		cin>>s;
		n=s.size();
		vector<int> o,e;
		int en=0,on=0;
		FOR(i,0,n)
		{
			if((s[i]-'0')%2==0)
			{
				e.pb(s[i]-'0');
				en++;
			}
			else
			{
				o.pb(s[i]-'0');
				on++;
			}
		}
		int p=0,q=0;
		o.pb(10);
		e.pb(10);
		FOR(i,0,n)
		{
			if(o[p]<e[q])
			{
				cout<<o[p];
				p++;
			}
			else
			{
				cout<<e[q];
				q++;
			}
		}
		cout<<'\n';
	}
	return 0;
}