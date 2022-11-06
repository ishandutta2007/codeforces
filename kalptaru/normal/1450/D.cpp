#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e9;
ll po(ll a,ll b){
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
	while(test--)
	{
		int n;
		cin>>n;
		int a[n];
		bool b[n]={0};
		int c=0;
		set<pair<int,int> > s;
		pair<int,int> o;
		FOR(i,0,n)
		{
			cin>>a[i];
			s.insert(mp(a[i],i));
			if(b[a[i]-1]==0)
				c++;
			b[a[i]-1]=1;
		}
		bool ans[n]={0};
		if(c==n)
		{
			ans[0]=1;
		}
		int l=0,r=n-1;
		FORD(i,n,1)
		{
			o=*s.begin();
			if(o.first==(n-i))
			{
				ans[i]=1;
			}
			else
			{
				break;
			}
			if(a[l]<a[r])
			{
				s.erase(mp(a[l],l));
				l++;
			}
			else
			{
				s.erase(mp(a[r],r));
				r--;
			}
		}
		FOR(i,0,n)
		cout<<ans[i];
		cout<<'\n';
	}
	return 0;
}