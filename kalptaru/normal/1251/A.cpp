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
		cin>>s;
		int n=s.size();
		char p=s[0];
		int cnt=1;
		bool f[26]={0};
		FOR(i,1,n)
		{
			if(s[i]==p)
			{
				cnt++;
			}
			else
			{
				if(cnt%2==1)
				f[p-'a']=1;
				cnt=1;
				p=s[i];
			}
		}
		if(cnt%2==1)
		f[p-'a']=1;
		FOR(i,0,26)
		{
			if(f[i])
			cout<<char(i+'a');
		}
		cout<<'\n';
	}
	return 0;
}